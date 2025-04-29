#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include <wiringPi.h> // is the gpio library
#include <softPwm.h> // makes pwm possible


using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses a fancy C++11 lambda
* function to shorten the callback syntax, at the expense of making the
* code somewhat more difficult to understand at first glance. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("topic", 10);
    auto timer_callback =
      [this]() -> void {
        int pwmval2 = 50;
        int led2 = 17; 
        wiringPiSetupGpio(); // this functions setups the bcm pin numbering for use
        // now creates pwm values.
        softPwmCreate(led2,0,255);

        auto message = std_msgs::msg::Int32();
        message.data =  pwmval2;
        softPwmWrite(led2,pwmval2);
        delay(2000);
        softPwmWrite(led2,0);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%i'", message.data);
        this->publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(500ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}