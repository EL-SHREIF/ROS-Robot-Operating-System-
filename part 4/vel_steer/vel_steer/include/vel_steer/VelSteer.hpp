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
#include "math.h"
namespace vel_steer {
 class VelSteer
{
 
 public:
 	/*!
 	 * Constructor.
 	 */
	VelSteer(ros::NodeHandle& nodeHandle);

 	/*!
 	 * Destructor.
 	 */
 	virtual ~VelSteer();
	int U;
 	int V;
 private:
 	ros::NodeHandle nodeHandle_;
 	ros::Subscriber subscriber_;
 	ros::Publisher publisher_;

 	float Xa,Ya,Za,Wa,FXa,FYa,FZa,FWa,RXa,RYa,RZa,RWa;

 	int i=0;
 	int j=0;
 	int k=0;
 	float Theta1=0;
 	float rev=0;
 	float Theta=0;
 	float steer=0.0,curSteer=0.0,prevSteer=0.0;
 	ros::Time  T;
 	float RPS=0;
 	float Velocity=0;
 	ros::Time secs;
 	ackermann_msgs::AckermannDrive ackerMsg;

 	void topicCallback(const gazebo_msgs::LinkStates::ConstPtr& msg);


 };

}
