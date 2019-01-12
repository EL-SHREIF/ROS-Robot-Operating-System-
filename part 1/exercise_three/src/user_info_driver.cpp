#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <exercise_three/UserInfo.h>
#include "std_msgs/Float64.h"


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
    exercise_three::UserInfo message;
	std::cout<<"Name : ";
	std::cin>> message.name;
	std::cout<<"age : ";
	std::cin>> message.age;
	std::cout<<"height : ";
	std::cin>> message.height;


		

    ss << "name:"<<message.name<<", age:"<<message.age<<", height:"<< message.height;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    hi.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
