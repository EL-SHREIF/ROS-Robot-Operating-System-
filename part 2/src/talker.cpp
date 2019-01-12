#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher user_data_info = n.advertise<std_msgs::String>("raw_data", 100);

  ros::Rate loop_rate(1);

while (ros::ok())
  {
    
    std_msgs::String msg;
#    std_msgs::int64 age;
#   std_msgs::int64 height;

    std::stringstream ss;
    ss <<name<<age<<height;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    user_data_info.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
