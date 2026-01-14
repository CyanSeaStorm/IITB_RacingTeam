#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <geometry_msgs/msg/point.hpp>

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
    dt_    = 0.05;  // timestep

    // ================= INITIAL STATE =================
    x_ = A_;
    v_ = 0.0;

    marker_pub_ =
      this->create_publisher<visualization_msgs::msg::Marker>(
        "visualization_marker", 10);

    timer_ = this->create_wall_timer(
      std::chrono::duration<double>(dt_),
      std::bind(&DampedSHM::stepSimulation, this));
  }

private:
  // ================= PHYSICS STEP =================
  void stepSimulation()
  {
    // Acceleration from ODE (NO trig / exp)
    double a = -2.0 * beta_ * v_ - omega_ * omega_ * x_;

    // Semi-implicit Euler
    v_ += a * dt_;
    x_ += v_ * dt_;

    rclcpp::Time now = this->now();

    // -------- CENTER --------
    visualization_msgs::msg::Marker center;
    center.header.frame_id = "base_link";
    center.header.stamp = now;
    center.ns = "damped_shm";
    center.id = 0;
    center.type = visualization_msgs::msg::Marker::CYLINDER;
    center.action = visualization_msgs::msg::Marker::ADD;

    center.pose.position.x = 0.0;
    center.pose.position.y = 0.0;
    center.pose.position.z = 0.25;
    center.pose.orientation.w = 1.0;

    center.scale.x = 0.2;
    center.scale.y = 0.2;
    center.scale.z = 0.5;

    center.color.g = 1.0f;
    center.color.a = 1.0f;

    // -------- BALL --------
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

    // -------- SPRING --------
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

    // -------- LOG --------
    RCLCPP_INFO(
      this->get_logger(),
      "x=%.3f | v=%.3f | a=%.3f",
      x_, v_, a);
  }

  // ================= MEMBERS =================
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  double x_, v_;
  double A_, beta_, omega_, dt_;
};

// ================= MAIN =================
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DampedSHM>());
  rclcpp::shutdown();
  return 0;
}
