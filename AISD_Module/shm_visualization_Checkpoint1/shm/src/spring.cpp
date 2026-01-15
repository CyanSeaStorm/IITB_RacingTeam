#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/float64.hpp>

// Services
#include "shm/srv/set_shm_params.hpp"
#include "shm/srv/apply_force.hpp"

#include <chrono>

using namespace std::chrono_literals;

class DampedSHM : public rclcpp::Node
{
public:
  DampedSHM()
  : Node("damped_shm")
  {
    // ================= PARAMETERS =================
    A_     = 2.0;   // initial displacement
    beta_  = 0.3;   // damping coefficient
    omega_ = 2.0;   // angular frequency
    mass_  = 1.0;   // mass
    dt_    = 0.05;  // timestep

    // ================= INITIAL STATE =================
    x_ = A_;
    v_ = 0.0;
    a_ = 0.0;
    Fext_ = 0.0;

    // ================= PUBLISHERS =================
    marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(
      "visualization_marker", 10);

    ke_pub_ = this->create_publisher<std_msgs::msg::Float64>("ke", 10);
    pe_pub_ = this->create_publisher<std_msgs::msg::Float64>("pe", 10);

    // ================= SERVICES =================
    service_ = this->create_service<shm::srv::SetSHMParams>(
      "set_shm_params",
      std::bind(
        &DampedSHM::setParamsCallback,
        this,
        std::placeholders::_1,
        std::placeholders::_2));

    apply_force_service_ = this->create_service<shm::srv::ApplyForce>(
      "apply_force",
      std::bind(
        &DampedSHM::applyForceCallback,
        this,
        std::placeholders::_1,
        std::placeholders::_2));

    // ================= TIMER =================
    timer_ = this->create_wall_timer(
      std::chrono::duration<double>(dt_),
      std::bind(&DampedSHM::stepSimulation, this));

    RCLCPP_INFO(this->get_logger(), "Damped SHM node started");
  }

private:
  // ================= SERVICE CALLBACKS =================
  void setParamsCallback(
    const std::shared_ptr<shm::srv::SetSHMParams::Request> req,
    std::shared_ptr<shm::srv::SetSHMParams::Response> res)
  {
    if (req->mass <= 0.0 || req->omega <= 0.0) {
      res->success = false;
      res->message = "Mass and omega must be positive";
      return;
    }

    mass_  = req->mass;
    omega_ = req->omega;
    beta_  = req->beta;

    res->success = true;
    res->message = "SHM parameters updated";

    RCLCPP_INFO(this->get_logger(),
      "Updated → mass=%.2f omega=%.2f beta=%.2f",
      mass_, omega_, beta_);
  }

  void applyForceCallback(
    const std::shared_ptr<shm::srv::ApplyForce::Request> req,
    std::shared_ptr<shm::srv::ApplyForce::Response> res)
  {
    Fext_ = req->force;  // set external force
    res->success = true;
    res->message = "External force applied";
    RCLCPP_INFO(this->get_logger(),
      "Applied external force: %.3f N", Fext_);
  }

  // ================= PHYSICS STEP =================
  void stepSimulation()
  {
    // Compute acceleration: (-2βv − mω²x + Fext) / m
    a_ = (-2.0 * beta_ * v_ - mass_ * omega_ * omega_ * x_ + Fext_) / mass_;

    // Semi-implicit Euler integration
    v_ += a_ * dt_;
    x_ += v_ * dt_;

    rclcpp::Time now = this->now();

    // ================= ENERGY =================
    double k = mass_ * omega_ * omega_;

    std_msgs::msg::Float64 ke_msg;
    std_msgs::msg::Float64 pe_msg;

    ke_msg.data = 0.5 * mass_ * v_ * v_;
    pe_msg.data = 0.5 * k * x_ * x_;

    ke_pub_->publish(ke_msg);
    pe_pub_->publish(pe_msg);

    // ================= RVIZ MARKERS =================

    // ---- CENTER ----
    visualization_msgs::msg::Marker center;
    center.header.frame_id = "base_link";
    center.header.stamp = now;
    center.ns = "damped_shm";
    center.id = 0;
    center.type = visualization_msgs::msg::Marker::CYLINDER;
    center.action = visualization_msgs::msg::Marker::ADD;
    center.pose.position.z = 0.25;
    center.pose.orientation.w = 1.0;
    center.scale.x = 0.2;
    center.scale.y = 0.2;
    center.scale.z = 0.5;
    center.color.g = 1.0f;
    center.color.a = 1.0f;

    // ---- BALL ----
    visualization_msgs::msg::Marker ball;
    ball.header.frame_id = "base_link";
    ball.header.stamp = now;
    ball.ns = "damped_shm";
    ball.id = 1;
    ball.type = visualization_msgs::msg::Marker::SPHERE;
    ball.action = visualization_msgs::msg::Marker::ADD;
    ball.pose.position.x = x_;
    ball.pose.position.z = 0.25;
    ball.pose.orientation.w = 1.0;
    ball.scale.x = 0.3;
    ball.scale.y = 0.3;
    ball.scale.z = 0.3;
    ball.color.r = 1.0f;
    ball.color.a = 1.0f;

    // ---- SPRING ----
    visualization_msgs::msg::Marker spring;
    spring.header.frame_id = "base_link";
    spring.header.stamp = now;
    spring.ns = "damped_shm";
    spring.id = 2;
    spring.type = visualization_msgs::msg::Marker::LINE_STRIP;
    spring.action = visualization_msgs::msg::Marker::ADD;
    spring.scale.x = 0.05;
    spring.color.b = 1.0f;
    spring.color.a = 1.0f;

    geometry_msgs::msg::Point p1, p2;
    p1.x = 0.0; p1.z = 0.25;
    p2.x = x_;  p2.z = 0.25;
    spring.points = {p1, p2};

    marker_pub_->publish(center);
    marker_pub_->publish(ball);
    marker_pub_->publish(spring);
  }

  // ================= MEMBERS =================
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr ke_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pe_pub_;
  rclcpp::Service<shm::srv::SetSHMParams>::SharedPtr service_;
  rclcpp::Service<shm::srv::ApplyForce>::SharedPtr apply_force_service_;
  rclcpp::TimerBase::SharedPtr timer_;

  double x_, v_, a_;
  double A_, beta_, omega_, mass_, dt_;
  double Fext_;
};

// ================= MAIN =================
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DampedSHM>());
  rclcpp::shutdown();
  return 0;
}
