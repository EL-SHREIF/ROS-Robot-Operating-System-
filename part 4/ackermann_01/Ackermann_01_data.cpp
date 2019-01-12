//
// File: Ackermann_01_data.cpp
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
#include "Ackermann_01.h"
#include "Ackermann_01_private.h"

// Block parameters (auto storage)
P rtP = {
  0.0,                                 // Variable: X_ic
                                       //  Referenced by: '<S7>/Integrator'

  -0.0,                                // Variable: Y_ic
                                       //  Referenced by: '<S7>/Integrator1'

  2.3,                                 // Variable: vehicle_length
                                       //  Referenced by: '<S7>/Gain'

  -1.5707963267948966,                 // Variable: yaw_ic
                                       //  Referenced by: '<S7>/Integrator2'


  {
    {
      0U,                              // Seq

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // FrameId_SL_Info

      {
        0,                             // Sec
        0                              // Nsec
      }                                // Stamp
    },                                 // Header

    {
      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      ,                                // Covariance

      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      }                                // Pose
    }                                  // Pose
  },                                   // Computed Parameter: Constant_Value
                                       //  Referenced by: '<S1>/Constant'


  {
    0.0F,                              // SteeringAngle
    0.0F,                              // SteeringAngleVelocity
    0.0F,                              // Speed
    0.0F,                              // Acceleration
    0.0F                               // Jerk
  },                                   // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S8>/Out1'


  {
    0.0F,                              // SteeringAngle
    0.0F,                              // SteeringAngleVelocity
    0.0F,                              // Speed
    0.0F,                              // Acceleration
    0.0F                               // Jerk
  },                                   // Computed Parameter: Constant_Value_a
                                       //  Referenced by: '<S5>/Constant'

  0.0,                                 // Expression: 0
                                       //  Referenced by: '<Root>/pitch'

  0.0,                                 // Expression: 0
                                       //  Referenced by: '<Root>/roll'

  0.5,                                 // Expression: 0.5
                                       //  Referenced by: '<S4>/1//2'

  0.434782594F                         // Computed Parameter: uL_Gain
                                       //  Referenced by: '<S7>/1//L'

};

//
// File trailer for generated code.
//
// [EOF]
//
