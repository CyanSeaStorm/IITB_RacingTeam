#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class VCUNode : public rclcpp::Node
{
public:
    VCUNode() : Node("vcu_node")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("VCU2AI", 10);
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "AI2VCU", 10,
            [this](std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "FROM AI TO VCU: '%s'", msg->data.c_str());
            });

        timer_ = this->create_wall_timer(1s, [this]() {
            auto message = std_msgs::msg::String();
            message.data = "FROM VCU TO AI";
            publisher_->publish(message);
        });
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VCUNode>());
    rclcpp::shutdown();
    return 0;
}
