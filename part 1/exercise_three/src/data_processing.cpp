
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <std_msgs/Int64.h>
#include <exercise_three/UserInfo.h>
#include <fstream>
#include "std_msgs/Float64.h"
#include <iomanip>
#include <stdio.h>
#include <sstream>

int strToint (std::string str){
	int sum=0;
	char x;
	for(int i=0;i< str.size();i++){
		x=str[i];
		sum=(sum*10)+(x-48);
	}
	return sum;
}

exercise_three::UserInfo message;

void hiCallback(const std_msgs::String msg)
{

	std::string shiko =msg.data;
        int i=msg.data.find(":");
        int j=msg.data.find(",");
	std::string name= msg.data.substr (i+1,j-i-1);
	shiko.erase (0,j+1);
 
	i=shiko.find(":");
        j=shiko.find(",");
	std::string age_tmp =shiko.substr (i+1,j-i-1);
	int age= strToint (age_tmp);
	shiko.erase (0,j+1);
  	
	i=shiko.find(":");
	std::string he =shiko.substr (i+1);
	std::stringstream ss2;      
 	ss2 << he;
	
	
        float height;

        ss2 >> height;


        std::stringstream ss;
        ss << name;
        message.name=ss.str();

        message.age=age;

	message.height=height;

	ROS_INFO("I will publish [name:%s,age:%i,height:%f]", message.name.c_str(), message.age,message.height);
	
        
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv,"data_processing");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("raw_data", 1000, hiCallback);
  ros::Publisher pup = n.advertise<exercise_three::UserInfo>("user_info", 1000);
  ros::Rate loop_rate(1);
  pup.publish(message);

 
  ros::spin();
  return 0;
}
