#include "ros/ros.h"
#include "std_msgs/String.h"

void my_callback(const std_msgs::String::ConstPtr &msg)
{
  ROS_INFO("I heard: %s", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Node initialization
  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle nh;

  // Subscribe topic
  ros::Subscriber my_sub = nh.subscribe<std_msgs::String>("simple_topic", 1000, my_callback);

  // Receve Callback 
  ros::spin();
}
