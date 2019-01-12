#pragma once

#include <ros/ros.h>
#include "std_msgs/String.h"
#include  "gazebo_msgs/LinkStates.h"
#include "geometry_msgs/Pose.h"
#include <ackermann_msgs/AckermannDrive.h>
#include <eigen3/Eigen/Dense>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>
#include "std_msgs/Float64.h"
#include "math.h"
namespace our_model {
 class pos
{
 
 public:
 	/*!
 	 * Constructor.
 	 */
	pos(ros::NodeHandle& nodeHandle);

 	/*!
 	 * Destructor.
 	 */
 	virtual ~pos();
	int X;
 	int Y;
 private:
 	ros::NodeHandle nodeHandle_;
 	ros::Subscriber subscriber_;
 	ros::Publisher publisher_;
	float vel,steer,pos_x,pos_y,Z1,Z2,Z3,Z4,P1,P2,dt;
	float L=2;	
	float Y1=0;
 	float Y2=0;
 	float Y3=0;
 	float Y4=0;
 	ros::Time  T;
 	ros::Time secs;
 	ackermann_msgs::AckermannDrive ackerMsg;

 	void topicCallback(const ackermann_msgs::AckermannDrive::ConstPtr& msg);

 };

}
