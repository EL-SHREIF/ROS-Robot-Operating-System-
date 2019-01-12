//
// File: Ackermann_01_types.h
//
// Code generated for Simulink model 'Ackermann_01'.
//
// Model version                  : 1.263
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu Nov 08 22:54:02 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Emulation hardware selection:
//    Differs from embedded hardware (MATLAB Host)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_Ackermann_01_types_h_
#define RTW_HEADER_Ackermann_01_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  int32_T Sec;
  int32_T Nsec;
} SL_Bus_Ackermann_01_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;

  // MsgType=ros_time/Time
  SL_Bus_Ackermann_01_ros_time_Time Stamp;
} SL_Bus_Ackermann_01_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_Ackermann_01_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T W;
} SL_Bus_Ackermann_01_geometry_msgs_Quaternion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
typedef struct {
  // MsgType=geometry_msgs/Point
  SL_Bus_Ackermann_01_geometry_msgs_Point Position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_Ackermann_01_geometry_msgs_Quaternion Orientation;
} SL_Bus_Ackermann_01_geometry_msgs_Pose;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
typedef struct {
  real_T Covariance[36];

  // MsgType=geometry_msgs/Pose
  SL_Bus_Ackermann_01_geometry_msgs_Pose Pose;
} SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped_

// MsgType=geometry_msgs/PoseWithCovarianceStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_Ackermann_01_std_msgs_Header Header;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovariance Pose;
} SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive_
#define DEFINED_TYPEDEF_FOR_SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive_

// MsgType=ackermann_msgs/AckermannDrive
typedef struct {
  real32_T SteeringAngle;
  real32_T SteeringAngleVelocity;
  real32_T Speed;
  real32_T Acceleration;
  real32_T Jerk;
} SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive;

#endif

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_P
#define typedef_robotics_slros_internal_block_P

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_P;

#endif                                 //typedef_robotics_slros_internal_block_P

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 //struct_tag_saG5948SFTrUFnIbVUb0TZH

#ifndef typedef_robotics_slros_internal_block_S
#define typedef_robotics_slros_internal_block_S

typedef struct tag_saG5948SFTrUFnIbVUb0TZH robotics_slros_internal_block_S;

#endif                                 //typedef_robotics_slros_internal_block_S

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  char_T f0[4];
} struct_T;

#endif                                 //typedef_struct_T

#ifndef typedef_struct_T_o
#define typedef_struct_T_o

typedef struct {
  char_T f0[8];
} struct_T_o;

#endif                                 //typedef_struct_T_o

#ifndef typedef_struct_T_ow
#define typedef_struct_T_ow

typedef struct {
  char_T f0[7];
} struct_T_ow;

#endif                                 //typedef_struct_T_ow

#ifndef typedef_struct_T_owv
#define typedef_struct_T_owv

typedef struct {
  char_T f0[8];
  char_T f1[7];
  char_T f2[6];
} struct_T_owv;

#endif                                 //typedef_struct_T_owv

// Parameters (auto storage)
typedef struct P_ P;

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#endif                                 // RTW_HEADER_Ackermann_01_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
