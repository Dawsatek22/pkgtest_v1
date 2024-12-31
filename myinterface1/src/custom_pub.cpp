#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "myinterface1/msg/Val1.msg.hpp"

using namespace std::chrono_literals;

class Val1interface1 : public rclpp::Node {
  public:
  Val1interface1():

  Node("mine_publisher1") {
    mypublisher1_ = 
    this->create_publisher<myinterface1::msg::Val1>("int_topic",10);

    auto Pub_msg = [this]() -> void {
auto msg = myinterface1::msg::val1();
msg.sendval = 2024;

std::cout << "my custom interface sends a value of" << msg.sendval << "For the first time"
<< std::endl;
this-> data_publisher_->publish(msg);
    };
    timer_ = this->create_wall_timer(1s, publish_msg);

    }
private:
rclcpp::publisher<myinterface1::msg::Val1>::SharedPtr> mypublisher1_
rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[]) {

rclccp::init(argc, argv);
rclcpp::spin(std::make_shared<mypublisher1_>());
rclcpp::shutdown();

}