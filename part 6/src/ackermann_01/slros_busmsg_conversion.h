#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <ackermann_msgs/AckermannDrive.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Quaternion.h>
#include <ros/time.h>
#include <std_msgs/Header.h>
#include "Ackermann_01_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(ackermann_msgs::AckermannDrive* msgPtr, SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive* busPtr, ackermann_msgs::AckermannDrive const* msgPtr);

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr);

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr);

void convertFromBus(geometry_msgs::PoseWithCovarianceStamped* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped* busPtr, geometry_msgs::PoseWithCovarianceStamped const* msgPtr);

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr);

void convertFromBus(ros::Time* msgPtr, SL_Bus_Ackermann_01_ros_time_Time const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_ros_time_Time* busPtr, ros::Time const* msgPtr);

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_Ackermann_01_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_Ackermann_01_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr);


#endif
