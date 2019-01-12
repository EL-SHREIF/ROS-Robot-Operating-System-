#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "Ackermann_01";

// For Block Ackermann_01/Subscribe
SimulinkSubscriber<ackermann_msgs::AckermannDrive, SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive> Sub_Ackermann_01_205;

// For Block Ackermann_01/Publish
SimulinkPublisher<geometry_msgs::PoseWithCovarianceStamped, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped> Pub_Ackermann_01_191;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

