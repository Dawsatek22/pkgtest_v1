
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "icpp_pubsub/msg/val1.hpp" // is my own custom  message header

using namespace std::chrono_literals;

class Int32_Subscriber : public rclcpp::Node {
    public:
    Int32_Subscriber()
    :Node("Int32_Subscriber")
    { auto topic_callback = 
    [this] (icpp_pubsub::msg::Val1::UniquePtr message) -> void {
    RCLCPP_INFO(this->get_logger(),"I receive '%d' ", message->sendval);
};
subscription_ =
this->create_subscription<icpp_pubsub::msg::Val1>("int32_topic",10,topic_callback);
    }

    private:
    rclcpp::Subscription<icpp_pubsub::msg::Val1>::SharedPtr subscription_;             // CHANGE


};
int main(int argc,char * argv[]) {

rclcpp::init(argc, argv);
rclcpp::spin(std::make_shared<Int32_Subscriber>());
rclcpp::shutdown();

return 0;
}