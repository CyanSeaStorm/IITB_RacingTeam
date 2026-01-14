#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <geometry_msgs/msg/point.hpp>

#include <cmath>

class DampedSHM : public rclcpp::Node
{
public:
  DampedSHM() : Node("damped_shm")
  {
    // Publisher
    marker_pub_ =
      this->create_publisher<visualization_msgs::msg::Marker>(
        "visualization_marker", 10);

    // Time zero = simulation start
    start_time_ = this->now();

    // Timer only triggers updates (NOT physics time)
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(50),
      std::bind(&DampedSHM::publishMarkers, this));
  }

private:
  void publishMarkers()
  {
    // ROS time
    rclcpp::Time now = this->now();

    // Time since simulation started
    static double t = 0.0;
    t += 0.05;   // matches 50 ms timer


    // ================= DAMPED SHM PARAMETERS =================
    const double A     = 2.0;   // amplitude
    const double beta  = 0;   // damping coefficient (visible)
    const double omega = 2.0;   // angular frequency

    // Damped SHM equation
    double x = A * std::exp(-beta * t) * std::cos(omega * t);

    // ================= CENTER (CYLINDER) =================
    visualization_msgs::msg::Marker center;
    center.header.frame_id = "base_link";
    center.header.stamp = now;
    center.ns = "damped_shm";
    center.id = 0;
    center.type = visualization_msgs::msg::Marker::CYLINDER;
    center.action = visualization_msgs::msg::Marker::ADD;

    center.pose.position.x = 0.0;
    center.pose.position.y = 0.0;
    center.pose.position.z = 0.25;   // lifted from grid
    center.pose.orientation.w = 1.0;

    center.scale.x = 0.2;
    center.scale.y = 0.2;
    center.scale.z = 0.5;

    center.color.r = 0.0f;
    center.color.g = 1.0f;
    center.color.b = 0.0f;
    center.color.a = 1.0f;

    // ================= BALL (SPHERE) =================
    visualization_msgs::msg::Marker ball;
    ball.header.frame_id = "base_link";
    ball.header.stamp = now;
    ball.ns = "damped_shm";
    ball.id = 1;
    ball.type = visualization_msgs::msg::Marker::SPHERE;
    ball.action = visualization_msgs::msg::Marker::ADD;

    ball.pose.position.x = x;
    ball.pose.position.y = 0.0;
    ball.pose.position.z = 0.25;
    ball.pose.orientation.w = 1.0;

    ball.scale.x = 0.3;
    ball.scale.y = 0.3;
    ball.scale.z = 0.3;

    ball.color.r = 1.0f;
    ball.color.g = 0.0f;
    ball.color.b = 0.0f;
    ball.color.a = 1.0f;

    // ================= SPRING (LINE_STRIP) =================
    visualization_msgs::msg::Marker spring;
    spring.header.frame_id = "base_link";
    spring.header.stamp = now;
    spring.ns = "damped_shm";
    spring.id = 2;
    spring.type = visualization_msgs::msg::Marker::LINE_STRIP;
    spring.action = visualization_msgs::msg::Marker::ADD;

    spring.scale.x = 0.05;

    spring.color.r = 0.0f;
    spring.color.g = 0.0f;
    spring.color.b = 1.0f;
    spring.color.a = 1.0f;

    geometry_msgs::msg::Point p1, p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p1.z = 0.25;

    p2.x = x;
    p2.y = 0.0;
    p2.z = 0.25;

    spring.points = {p1, p2};

    // ================= PUBLISH =================
    marker_pub_->publish(center);
    marker_pub_->publish(ball);
    marker_pub_->publish(spring);
  }

  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Time start_time_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DampedSHM>());
  rclcpp::shutdown();
  return 0;
}
