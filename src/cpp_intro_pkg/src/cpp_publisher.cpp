#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class CppPublisher : public rclcpp::Node
{
public:
    CppPublisher() : Node("cpp_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("cpp_topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&CppPublisher::publish_message, this)
        );
    }

private:
    void publish_message()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello from C++ ROS2 publisher!";
        publisher_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CppPublisher>());
    rclcpp::shutdown();
    return 0;
}
