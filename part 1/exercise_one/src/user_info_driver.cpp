#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "user_info_driver");
  ros::NodeHandle n;
  ros::Publisher hi = n.advertise<std_msgs::String>("raw_data", 1000);
  ros::Rate loop_rate(1);
  while (ros::ok())
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "name:Rose, age:20, height: 170 ";
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    hi.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
