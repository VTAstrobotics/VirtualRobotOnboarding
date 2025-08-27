#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"


using std::placeholders::_1;
/**
 * YOUR OBJECTIVE - take in the /cmd_vel topic, and publish a velocity to /left_drive and /right_drive
 * according to the velocity (assume a tank drive robot).
 * 
 */
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      velocity_subscriber = this->create_subscription<YOUR::MESSAGE::TYPE>(//fill in message type
      "/hello_world", 10, std::bind(&MinimalSubscriber::velocity_callback, this, _1));
    }

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      //your callback code here: this should include the code you want to run every time
      // a new mesage is recieved on your subscription
    }
    rclcpp::Subscription<YOUR::MESSAGE::TYPE>::SharedPtr velocity_subscriber; //fill in the message type you are recieving
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}