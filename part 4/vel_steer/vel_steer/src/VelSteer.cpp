#include "vel_steer/VelSteer.hpp"

namespace vel_steer {

VelSteer::VelSteer(ros::NodeHandle& nodeHandle) :
		nodeHandle_(nodeHandle) {
	std::string topic;
	int queue_size;

	// get parameter from config.yaml
	if (!nodeHandle.getParam("topic", topic)) {
		ROS_ERROR("Could not find topic parameter!");
	}

	if (!nodeHandle.getParam("queue_size", queue_size)) {
		ROS_ERROR("Could not find queue_size parameter!");
	}

	// initialize subscriber and publisher
	subscriber_ = nodeHandle.subscribe(topic, queue_size,
			&VelSteer::topicCallback, this);

	publisher_ = nodeHandle.advertise < ackermann_msgs::AckermannDrive
			> ("/ackermann_data", 10, true);

}
VelSteer::~VelSteer() {
}

void VelSteer::topicCallback(const gazebo_msgs::LinkStates::ConstPtr& msg) {

	secs = ros::Time::now();
	prevSteer = curSteer;

	if (i == 0) {
		for (i; i < 1000; i++) {
			std::string U = msg->name[i];
			if (U.compare("urban::Body") == 0)
				break;
		}
		for (j; j < 1000; j++) {
			std::string U = msg->name[j];
			if (U.compare("urban::front_left_wheel") == 0)
				break;
		}

		for (k; k < 1000; k++) {
			std::string U = msg->name[k];
			if (U.compare("urban::rear_left_wheel") == 0) {
				break;
			}
		}
	}

	Xa = msg->pose[i].orientation.x;
	Ya = msg->pose[i].orientation.y;
	Za = msg->pose[i].orientation.z;
	Wa = msg->pose[i].orientation.w;

	FXa = msg->pose[j].orientation.x;
	FYa = msg->pose[j].orientation.y;
	FZa = msg->pose[j].orientation.z;
	FWa = msg->pose[j].orientation.w;

	RXa = msg->pose[k].orientation.x;
	RYa = msg->pose[k].orientation.y;
	RZa = msg->pose[k].orientation.z;
	RWa = msg->pose[k].orientation.w;

	Eigen::Matrix3f URW;
	URW << Wa * Wa + Xa * Xa - Ya * Ya - Za * Za, 2 * (Xa * Ya + Wa * Za), 2
			* (Xa * Za - Wa * Ya), 2 * (Xa * Ya - Wa * Za), Wa * Wa - Xa * Xa
			+ Ya * Ya - Za * Za, 2 * (Ya * Za + Wa * Xa), 2
			* (Xa * Za + Wa * Ya), 2 * (Ya * Za - Wa * Xa), Wa * Wa - Xa * Xa
			- Ya * Ya + Za * Za;

	Eigen::Matrix3f WRF;
	WRF << FWa * FWa + FXa * FXa - FYa * FYa - FZa * FZa, 2
			* (FXa * FYa - FWa * FZa), 2 * (FXa * FZa + FWa * FYa), 2
			* (FXa * FYa + FWa * FZa), FWa * FWa - FXa * FXa + FYa * FYa
			- FZa * FZa, 2 * (FYa * FZa - FWa * FXa), 2
			* (FXa * FZa - FWa * FYa), 2 * (FYa * FZa + FWa * FXa), FWa * FWa
			- FXa * FXa - FYa * FYa + FZa * FZa;

	Eigen::Matrix3f WRR;
	WRR << RWa * RWa + RXa * RXa - RYa * RYa - RZa * RZa, 2
			* (RXa * RYa - RWa * RZa), 2 * (RXa * RZa + RWa * RYa), 2
			* (RXa * RYa + RWa * RZa), RWa * RWa - RXa * RXa + RYa * RYa
			- RZa * RZa, 2 * (RYa * RZa - RWa * RXa), 2
			* (RXa * RZa - RWa * RYa), 2 * (RYa * RZa + RWa * RXa), RWa * RWa
			- RXa * RXa - RYa * RYa + RZa * RZa;

	Eigen::Matrix3f URF;
	URF = URW * WRF;

	steer = acos(-URF(1, 2));
	//ROS_INFO("Steering_Angle:%f\n",(steer*180/3.14));
	curSteer = steer;

	Eigen::Matrix3f URR;
	URR = URW * WRR;

	if (URR(0, 0) > 0 && URR(2, 0) > 0) {
		//  Theta= acos(URR(0,0));
		Theta = (2 * 3.14159265) - acos(URR(0, 0));
		Theta = (Theta * 180 / 3.14159265);
	}
	if (URR(0, 0) > 0 && URR(2, 0) < 0) {
		//Theta= (2*3.14159265)-acos(URR(0,0));
		Theta = acos(URR(0, 0));
		Theta = (Theta * 180 / 3.14159265);
	}
	if (URR(0, 0) < 0 && URR(2, 0) > 0) {

		//Theta= (3.14159265)-acos(-URR(0,0));
		Theta = (3.14159265) + acos(-URR(0, 0));
		Theta = (Theta * 180 / 3.14159265);
	}
	if (URR(0, 0) < 0 && URR(2, 0) < 0) {

		//Theta= (3.14159265)+acos(-URR(0,0));
		Theta = (3.14159265) - acos(-URR(0, 0));
		Theta = (Theta * 180 / 3.14159265);

	}

	//ROS_INFO("Theta:%f\n",(Theta));
	//ROS_INFO("Theta1:%f\n",(Theta1));

	rev = (Theta - Theta1) / 360;
	//ROS_INFO("rev:%f\n",(rev));

	ros::Duration diff = secs - T;
	//ROS_INFO("diff:%lf\n",(diff.toSec()));

	RPS = rev / (diff.toSec());
	//ROS_INFO("RPS:%f\n",(RPS));
	//ROS_INFO("secs:%lf\n",(secs.toSec()));
	//ROS_INFO("T:%lf\n",(T.toSec()));

	Velocity = RPS * 2 * 3.14159265 * 0.25;

	Theta1 = Theta;

	T = secs;

	//ackerMsg.header.stamp = ros::Time::now();
	//ackerMsg.header.frame_id = "urban::Body";
	ackerMsg.steering_angle = (curSteer-prevSteer);
	ackerMsg.speed = Velocity;
	publisher_ .publish(ackerMsg);

	ros::Duration(0.1).sleep();

}

}

/* namespace */

