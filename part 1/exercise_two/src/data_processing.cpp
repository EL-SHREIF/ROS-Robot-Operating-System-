
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <std_msgs/Int64.h>

int strToint (std::string str){
	int sum=0;
	char x;
	for(int i=0;i< str.size();i++){
		x=str[i];
		sum=(sum*10)+(x-48);
	}
	return sum;
}

std_msgs::String name_msg;
std_msgs::Int64 age_msg;
std_msgs::Int64 height_msg;


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
	std::string he_temp =shiko.substr (i+2,3);
	int height= strToint(he_temp);
        
        std::stringstream ss;
        ss << name;
        name_msg.data=ss.str();

        age_msg.data=age;
 
	height_msg.data=height;
	ROS_INFO("I will publish :[%s]", name_msg.data.c_str());
	ROS_INFO("I will publish :[%i]", age_msg.data);
        ROS_INFO("I will publish :[%i]", height_msg.data);	

        
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv,"data_processing");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("raw_data", 1000, hiCallback);
  ros::Publisher pup1 = n.advertise<std_msgs::String>("name", 1000);
  ros::Publisher pup2 = n.advertise<std_msgs::Int64>("age", 1000);
  ros::Publisher pup3 = n.advertise<std_msgs::Int64>("height", 1000);
  ros::Rate loop_rate(1);
  


  pup1.publish(name_msg);
  pup2.publish(age_msg);
  pup3.publish(height_msg); 
  
 


  ros::spin();
  return 0;
}
