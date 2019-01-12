//
// File: Ackermann_01.h
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
#ifndef RTW_HEADER_Ackermann_01_h_
#define RTW_HEADER_Ackermann_01_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Ackermann_01_COMMON_INCLUDES_
# define Ackermann_01_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // Ackermann_01_COMMON_INCLUDES_

#include "Ackermann_01_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#define Ackermann_01_M                 (rtM)

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive In1;// '<S8>/In1'
  SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive varargout_2;
  robotics_slros_internal_block_P obj; // '<S2>/SinkBlock'
  robotics_slros_internal_block_S obj_f;// '<S5>/SourceBlock'
  real_T VectorConcatenate[3];         // '<Root>/Vector Concatenate'
  real_T TmpSignalConversionAtHiddenToAs[4];// '<Root>/Rotation Angles to Quaternions' 
  real_T q0;                           // '<S4>/q0'
  real_T q1;                           // '<S4>/q1'
  real_T q2;                           // '<S4>/q2'
  real_T q3;                           // '<S4>/q3'
  real_T psidotrads;                   // '<S7>/Product2'
  real_T L2psidot;                     // '<S7>/Gain'
  real_T v_Xms;                        // '<S7>/Sum'
  real_T v_Yms;                        // '<S7>/Sum1'
  struct {
    void *AQHandles;
  } HiddenToAsyncQueue_InsertedFor_;   // synthesized block

  void *SourceBlock_PWORK;             // '<S5>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S2>/SinkBlock'
} DW;

// Continuous states (auto storage)
typedef struct {
  real_T Integrator2_CSTATE;           // '<S7>/Integrator2'
  real_T Integrator_CSTATE;            // '<S7>/Integrator'
  real_T Integrator1_CSTATE;           // '<S7>/Integrator1'
} X;

// State derivatives (auto storage)
typedef struct {
  real_T Integrator2_CSTATE;           // '<S7>/Integrator2'
  real_T Integrator_CSTATE;            // '<S7>/Integrator'
  real_T Integrator1_CSTATE;           // '<S7>/Integrator1'
} XDot;

// State disabled
typedef struct {
  boolean_T Integrator2_CSTATE;        // '<S7>/Integrator2'
  boolean_T Integrator_CSTATE;         // '<S7>/Integrator'
  boolean_T Integrator1_CSTATE;        // '<S7>/Integrator1'
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
typedef struct {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
} ODE3_IntgData;

#endif

// Parameters (auto storage)
struct P_ {
  real_T X_ic;                         // Variable: X_ic
                                       //  Referenced by: '<S7>/Integrator'

  real_T Y_ic;                         // Variable: Y_ic
                                       //  Referenced by: '<S7>/Integrator1'

  real_T vehicle_length;               // Variable: vehicle_length
                                       //  Referenced by: '<S7>/Gain'

  real_T yaw_ic;                       // Variable: yaw_ic
                                       //  Referenced by: '<S7>/Integrator2'

  SL_Bus_Ackermann_01_geometry_msgs_PoseWithCovarianceStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S1>/Constant'

  SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive Out1_Y0;// Computed Parameter: Out1_Y0
                                                            //  Referenced by: '<S8>/Out1'

  SL_Bus_Ackermann_01_ackermann_msgs_AckermannDrive Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                                     //  Referenced by: '<S5>/Constant'

  real_T pitch_Value;                  // Expression: 0
                                       //  Referenced by: '<Root>/pitch'

  real_T roll_Value;                   // Expression: 0
                                       //  Referenced by: '<Root>/roll'

  real_T u2_Gain;                      // Expression: 0.5
                                       //  Referenced by: '<S4>/1//2'

  real32_T uL_Gain;                    // Computed Parameter: uL_Gain
                                       //  Referenced by: '<S7>/1//L'

};

// Real-time Model Data Structure
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  ModelData:
  //  The following substructure contains information regarding
  //  the data used in the model.

  struct {
    X *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[3];
    real_T odeF[3][3];
    ODE3_IntgData intgData;
  } ModelData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P rtP;

#ifdef __cplusplus

}
#endif

// Continuous states (auto storage)
extern X rtX;

// Block signals and states (auto storage)
extern DW rtDW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Ackermann_01_initialize(void);
  extern void Ackermann_01_step(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S7>/Display' : Unused code path elimination
//  Block '<S7>/Trigonometric Function3' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Ackermann_01'
//  '<S1>'   : 'Ackermann_01/Blank Message'
//  '<S2>'   : 'Ackermann_01/Publish'
//  '<S3>'   : 'Ackermann_01/Qaut_elments '
//  '<S4>'   : 'Ackermann_01/Rotation Angles to Quaternions'
//  '<S5>'   : 'Ackermann_01/Subscribe'
//  '<S6>'   : 'Ackermann_01/run setup_tracked_a.m1'
//  '<S7>'   : 'Ackermann_01/simple kinematic 2D steered vehicle model'
//  '<S8>'   : 'Ackermann_01/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_Ackermann_01_h_

//
// File trailer for generated code.
//
// [EOF]
//
