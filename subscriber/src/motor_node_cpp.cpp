#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64.hpp"


using std::placeholders::_1;
/**
 * YOUR OBJECTIVE - subscribe to the /cmd_vel topic, and publish a velocity to /left_drive and /right_drive
 * according to the velocity (assume a tank drive robot). Finish all of the TODOs in the code!
 * 
 * MESSAGE TYPES
 * SUBSCRIPTIONS
 *  * /cmd_vel (geometry_msgs/msg/Twist) 
 * PUBLISHERS
 *   /left_drive  (std_msgs/msg/Float64)
 *   /right_drive (std_msgs/msg/Float64)

 * 
 * 
 * use these equations, which are standard for a tank drive robot (assume a wheelbase of 1 meter):
 * 
 * Left Velocity = Linear Velocity x - 0.5 * Angular Velocity z * Wheelbase
 * 
 * Right Velocity = Linear Velocity x + 0.5 * Angular Velocity z * Wheelbase.
 * 
 * 
 * 
 */
class MotorNode : public rclcpp::Node
{
  public:
    MotorNode()
    : Node("motor_node")
    {
      //this is where you assign subscribers and publishers to a topic.

      velocity_subscriber = this->create_subscription<geometry_msgs::msg::Twist>( // TODO(1): fill in message type for your velocity subscriber! should be a twist message type.
      "/cmd_vel", 10, std::bind(&MotorNode::your_callback, this, _1)); //TODO(2), change topic so subscriber listens to /cmd_vel topic. You should change the string on this line




      left_publisher = this->create_publisher<std_msgs::msg::Float64>("/left_drive", 10);//example for left publisher.
      right_publisher = this->create_publisher<std_msgs::msg::Float64>("/right_drive", 10);
      //TODO(3) - assign the right publisher you create to a topic 
    }

  private:
    void your_callback(geometry_msgs::msg::Twist::SharedPtr msg)
    {  
      /***
       * TODO(4)
       * the method "your_callback" is run everytime your subscriber recieves a message. Here, do the math to find
       * the left motor and right motor velocities, and publish them to their respective topics using two publishers, one for /left_drive
       * and one for /right_drive
      */



        double lin_x_L = msg->linear.x;
        double ang_z_L = msg->angular.z; // this is how you get the x velocity from the message. Try angular z!

        std_msgs::msg::Float64 left_velocity;

        left_velocity.data = lin_x_L  - 0.5 * ang_z_L;//ROS2 messages require you to use .data to add information to the variable you are publishing
        left_publisher->publish(left_velocity); 
        /*** this is how you would publish a variable.
        Note that the variable is incomplete at this point (you have to do the math at the top to assign left_velocity to the right value)
        */
       double lin_x_R = msg->linear.x;
       double ang_z_R = msg->angular.z;

       std_msgs::msg::Float64 right_velocity;

       right_velocity.data = lin_x_R + 0.5 * ang_z_L;
       right_publisher->publish(right_velocity);
    }


    //this is where you can declare subscribers/publishers.


    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr velocity_subscriber; //note the message type (hint - TODO(1))

    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr left_publisher;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr right_publisher; // example for the /left_drive publisher. You need to make the right publisher.
    //TODO(5) - create the publisher for the right motor
    
};

int main(int argc, char * argv[])
{
  //you don't have to worry about changing any of this for now
  //this is the code that makes everything run
  rclcpp::init(argc, argv); 
  rclcpp::spin(std::make_shared<MotorNode>());
  rclcpp::shutdown();
  return 0;
}