// this is a node right now that publish int32 values. the run name is called: italk

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "icpp_pubsub/msg/val1.hpp" // is my own custom  message header.

using namespace std::chrono_literals;

class Int32_Publisher : public rclcpp::Node
{
public:
  Int32_Publisher()
  : Node("int32_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<icpp_pubsub::msg::Val1 >("int32_topic", 10);  // CHANGE

    auto timer_callback = [this](){
      auto message =  icpp_pubsub::msg::Val1();                                   // CHANGE
      message.sendval = 2024;        // because it is the year i did it.                                              // CHANGE
      RCLCPP_INFO_STREAM(this->get_logger(), "My first custom integer published is in the Year: '" << message.sendval << "'then");    // logging the message
      publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(500ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::Publisher<icpp_pubsub::msg::Val1>::SharedPtr publisher_;             // CHANGE
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Int32_Publisher>());
  rclcpp::shutdown();
  return 0;
}