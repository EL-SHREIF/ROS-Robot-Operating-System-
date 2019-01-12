#include "model/hello_model.hpp"

namespace our_model {

pos::pos(ros::NodeHandle& nodeHandle) :
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
			&pos::topicCallback, this);

	publisher_ = nodeHandle.advertise <std_msgs::String> ("/the_pos", 10, true);
}
pos::~pos() {
}

void pos::topicCallback(const ackermann_msgs::AckermannDrive::ConstPtr& msg) {

	
	steer = msg->steering_angle;
	vel = msg->speed;

	//ROS_INFO("Steering_Angle:%f\n",(steer));


	//ROS_INFO("velocity:%f\n",(vel));
	
	secs = ros::Time::now();
	
	ros::Duration diff = secs - T;

	dt=diff.toSec();

	Z1=(vel*(1/L))*steer;

	Y1=( Z1*dt );
	
	Z2= Z1 * (L/2) ;
	
	P1 = cos( Y1 ); 
	P2 = sin( Y2 );
	
	Y3=( (P1*vel) - (Z2*P2)  )*dt;

	Y4=( (P2*vel) + (Z2*P1)  )*dt;
	
	pos_x=Y4;
	pos_y=Y3;
	
	T=secs;
	
	std_msgs::String msg_data;

	std::stringstream ss;
	ss <<"the position x =  " <<pos_x<<"  the position Y =  "<<pos_y;
	msg_data.data = ss.str();
	publisher_ .publish(msg_data);
	ros::Duration(0.1).sleep();

}

}

/* namespace */

