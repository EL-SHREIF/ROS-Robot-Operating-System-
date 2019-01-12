
#include <ros/ros.h>
#include "vel_steer/VelSteer.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "vel_steer");
  ros::NodeHandle nodeHandle("~");

 vel_steer::VelSteer VelSteer(nodeHandle);
  ros::spin();
  return 0;
}
