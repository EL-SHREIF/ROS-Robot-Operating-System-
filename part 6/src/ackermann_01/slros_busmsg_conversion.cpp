#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive and ackermann_msgs::AckermannDrive

void convertFromBus(ackermann_msgs::AckermannDrive* msgPtr, SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive const* busPtr)
{
  const std::string rosMessageType("ackermann_msgs/AckermannDrive");

  msgPtr->acceleration =  busPtr->Acceleration;
  msgPtr->jerk =  busPtr->Jerk;
  msgPtr->speed =  busPtr->Speed;
  msgPtr->steering_angle =  busPtr->SteeringAngle;
  msgPtr->steering_angle_velocity =  busPtr->SteeringAngleVelocity;
}

void convertToBus(SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive* busPtr, ackermann_msgs::AckermannDrive const* msgPtr)
{
  const std::string rosMessageType("ackermann_msgs/AckermannDrive");

  busPtr->Acceleration =  msgPtr->acceleration;
  busPtr->Jerk =  msgPtr->jerk;
  busPtr->Speed =  msgPtr->speed;
  busPtr->SteeringAngle =  msgPtr->steering_angle;
  busPtr->SteeringAngleVelocity =  msgPtr->steering_angle_velocity;
}


// Conversions between SL_Bus_Ackermann_01_geometry_msgs_Point and geometry_msgs::Point

void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Point const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Ackermann_01_geometry_msgs_Pose and geometry_msgs::Pose

void convertFromBus(geometry_msgs::Pose* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Pose const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertFromBus(&msgPtr->orientation, &busPtr->Orientation);
  convertFromBus(&msgPtr->position, &busPtr->Position);
}

void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Pose* busPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  convertToBus(&busPtr->Orientation, &msgPtr->orientation);
  convertToBus(&busPtr->Position, &msgPtr->position);
}


// Conversions between SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance and geometry_msgs::PoseWithCovariance

void convertFromBus(geometry_msgs::PoseWithCovariance* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertFromBusFixedPrimitiveArray(msgPtr->covariance, busPtr->Covariance);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance* busPtr, geometry_msgs::PoseWithCovariance const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovariance");

  convertToBusFixedPrimitiveArray(busPtr->Covariance, msgPtr->covariance, slros::NoopWarning());
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped and geometry_msgs::PoseWithCovarianceStamped

void convertFromBus(geometry_msgs::PoseWithCovarianceStamped* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovarianceStamped");

  convertFromBus(&msgPtr->header, &busPtr->Header);
  convertFromBus(&msgPtr->pose, &busPtr->Pose);
}

void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped* busPtr, geometry_msgs::PoseWithCovarianceStamped const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/PoseWithCovarianceStamped");

  convertToBus(&busPtr->Header, &msgPtr->header);
  convertToBus(&busPtr->Pose, &msgPtr->pose);
}


// Conversions between SL_Bus_Ackermann_01_geometry_msgs_Quaternion and geometry_msgs::Quaternion

void convertFromBus(geometry_msgs::Quaternion* msgPtr, SL_Bus_Ackermann_01_geometry_msgs_Quaternion const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  busPtr->W;
  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_Ackermann_01_geometry_msgs_Quaternion* busPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  busPtr->W =  msgPtr->w;
  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_Ackermann_01_ros_time_Time and ros::Time

void convertFromBus(ros::Time* msgPtr, SL_Bus_Ackermann_01_ros_time_Time const* busPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->sec =  busPtr->Sec;
  msgPtr->nsec =  busPtr->Nsec;
}

void convertToBus(SL_Bus_Ackermann_01_ros_time_Time* busPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  busPtr->Sec =  msgPtr->sec;
  busPtr->Nsec =  msgPtr->nsec;
}


// Conversions between SL_Bus_Ackermann_01_std_msgs_Header and std_msgs::Header

void convertFromBus(std_msgs::Header* msgPtr, SL_Bus_Ackermann_01_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr->frame_id, busPtr->FrameId, busPtr->FrameId_SL_Info);
  msgPtr->seq =  busPtr->Seq;
  convertFromBus(&msgPtr->stamp, &busPtr->Stamp);
}

void convertToBus(SL_Bus_Ackermann_01_std_msgs_Header* busPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->FrameId, busPtr->FrameId_SL_Info, msgPtr->frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  busPtr->Seq =  msgPtr->seq;
  convertToBus(&busPtr->Stamp, &msgPtr->stamp);
}

