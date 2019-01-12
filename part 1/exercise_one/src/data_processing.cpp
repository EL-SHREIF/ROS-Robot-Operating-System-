
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
int strToint (std::string str){
	int sum=0;
	char x;
	for(int i=0;i< str.size();i++){
		x=str[i];
		sum=(sum*10)+(x-48);
	}
	return sum;
}

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

	ROS_INFO("\n Name:%s \n Age:%d \n Height:%d \n", name.c_str(), age, height);

}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv,"data_processing");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("raw_data", 1000, hiCallback);
  ros::spin();
  return 0;
}
