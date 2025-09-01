#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"


using std::placeholders::_1;
/**
 * YOUR OBJECTIVE - take in the /cmd_vel topic, and publish a velocity to /left_drive and /right_drive
 * according to the velocity (assume a tank drive robot).
 * 
 * 
 * use these equations, which are standard for a tank drive robot:
 * 
 * Left Velocity = Linear Velocity x - 0.5 * Angular Velocity z * Wheelbase
 * 
 * Right Velocity = Linear Velocity + 0.5 * Angular Velocity z * Wheelbase.
 * 
 * 
 * ***** assume a wheelbase of 1 meter ****
 * 
 */
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      velocity_subscriber = this->create_subscription<YOUR::MESSAGE::TYPE>(//fill in message type
      "/hello_world", 10, std::bind(&MinimalSubscriber::your_callback, this, _1));
    }

  private:
    void your_callback(const geometry_msgs::msg::Twist::SharedPtr msg) const
    {

    }
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr velocity_subscriber; //note the message type
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv); 
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}