#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block Ackermann_01/Subscribe
extern SimulinkSubscriber<ackermann_msgs::AckermannDrive, SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive> Sub_Ackermann_01_205;

// For Block Ackermann_01/Publish
extern SimulinkPublisher<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped> Pub_Ackermann_01_191;

void slros_node_init(int argc, char** argv);

#endif
