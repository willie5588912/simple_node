#include "ros/ros.h" 
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  // Node initialization
  ros::init(argc, argv, "publisher_node");
  ros::NodeHandle nh;

  // Advertise topic
  ros::Publisher my_pub = nh.advertise<std_msgs::String>("simple_topic", 1000);

  // Specify loop rate
  ros::Rate loop_rate(10);

  // Publish String message
  while(ros::ok())
  {
    // Add contents to String message
    std_msgs::String msg;
    msg.data = "hello world";

    // Publish String message
    my_pub.publish(msg);

    // Show what you have published
    ROS_INFO("%s", msg.data.c_str());

    // Loop control
    loop_rate.sleep();
  }
}
