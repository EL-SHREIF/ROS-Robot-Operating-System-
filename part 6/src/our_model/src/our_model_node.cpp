
#include <ros/ros.h>
#include "model/hello_model.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "our_model");
  ros::NodeHandle nodeHandle("~");

  our_model::pos pos(nodeHandle);
  ros::spin();
  return 0;
}
