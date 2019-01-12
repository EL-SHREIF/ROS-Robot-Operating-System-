//
// File: Ackermann_01.cpp
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
#define MessageQueueLen                (10)

// Continuous states
X rtX;

// Block signals and states (auto storage)
DW rtDW;

// Real-time model
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  Ackermann_01_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Ackermann_01_step();
  Ackermann_01_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Ackermann_01_step();
  Ackermann_01_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void Ackermann_01_step(void)
{
  boolean_T varargout_1;
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_sincos_o2_idx_2;
  real_T rtb_sincos_o1_idx_0;
  real_T rtb_sincos_o1_idx_1;
  real_T rtb_sincos_o1_idx_2;
  if (rtmIsMajorTimeStep(rtM)) {
    // set solver stop time
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  // SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' incorporates:
  //   Integrator: '<S7>/Integrator2'

  rtDW.VectorConcatenate[0] = rtX.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(rtM)) {
    // Constant: '<Root>/pitch'
    rtDW.VectorConcatenate[1] = rtP.pitch_Value;

    // Constant: '<Root>/roll'
    rtDW.VectorConcatenate[2] = rtP.roll_Value;
  }

  // Gain: '<S4>/1//2'
  rtb_sincos_o2_idx_2 = rtP.u2_Gain * rtDW.VectorConcatenate[0];

  // Trigonometry: '<S4>/sincos'
  rtb_sincos_o1_idx_0 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_0 = cos(rtb_sincos_o2_idx_2);

  // Gain: '<S4>/1//2'
  rtb_sincos_o2_idx_2 = rtP.u2_Gain * rtDW.VectorConcatenate[1];

  // Trigonometry: '<S4>/sincos'
  rtb_sincos_o1_idx_1 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_1 = cos(rtb_sincos_o2_idx_2);

  // Gain: '<S4>/1//2'
  rtb_sincos_o2_idx_2 = rtP.u2_Gain * rtDW.VectorConcatenate[2];

  // Trigonometry: '<S4>/sincos'
  rtb_sincos_o1_idx_2 = sin(rtb_sincos_o2_idx_2);
  rtb_sincos_o2_idx_2 = cos(rtb_sincos_o2_idx_2);

  // Fcn: '<S4>/q0'
  rtDW.q0 = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1 * rtb_sincos_o2_idx_2 +
    rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2;

  // Fcn: '<S4>/q1'
  rtDW.q1 = rtb_sincos_o2_idx_0 * rtb_sincos_o2_idx_1 * rtb_sincos_o1_idx_2 -
    rtb_sincos_o1_idx_0 * rtb_sincos_o1_idx_1 * rtb_sincos_o2_idx_2;

  // Fcn: '<S4>/q2'
  rtDW.q2 = rtb_sincos_o2_idx_0 * rtb_sincos_o1_idx_1 * rtb_sincos_o2_idx_2 +
    rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_1 * rtb_sincos_o1_idx_2;

  // Fcn: '<S4>/q3'
  rtDW.q3 = rtb_sincos_o1_idx_0 * rtb_sincos_o2_idx_1 * rtb_sincos_o2_idx_2 -
    rtb_sincos_o2_idx_0 * rtb_sincos_o1_idx_1 * rtb_sincos_o1_idx_2;
  if (rtmIsMajorTimeStep(rtM)) {
    // SignalConversion: '<Root>/TmpSignal ConversionAtHiddenToAsyncQueue_InsertedFor_Rotation Angles to Quaternions_at_outport_0Inport1' 
    rtDW.TmpSignalConversionAtHiddenToAs[0] = rtDW.q0;
    rtDW.TmpSignalConversionAtHiddenToAs[1] = rtDW.q1;
    rtDW.TmpSignalConversionAtHiddenToAs[2] = rtDW.q2;
    rtDW.TmpSignalConversionAtHiddenToAs[3] = rtDW.q3;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'
  //   Integrator: '<S7>/Integrator'
  //   Integrator: '<S7>/Integrator1'
  //   MATLAB Function: '<Root>/Qaut_elments '
  //   SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport1'

  // MATLAB Function 'Qaut_elments ': '<S3>:1'
  // '<S3>:1:3' x=u(1);
  // '<S3>:1:4' y=u(2);
  // '<S3>:1:5' z=u(3);
  // '<S3>:1:6' w=u(4);
  rtDW.BusAssignment = rtP.Constant_Value;
  rtDW.BusAssignment.Pose.Pose.Position.X = rtX.Integrator_CSTATE;
  rtDW.BusAssignment.Pose.Pose.Position.Y = rtX.Integrator1_CSTATE;
  rtDW.BusAssignment.Pose.Pose.Orientation.X = rtDW.q0;
  rtDW.BusAssignment.Pose.Pose.Orientation.Y = rtDW.q1;
  rtDW.BusAssignment.Pose.Pose.Orientation.Z = rtDW.q2;
  rtDW.BusAssignment.Pose.Pose.Orientation.W = rtDW.q3;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // Start for MATLABSystem: '<S2>/SinkBlock' incorporates:
  //   MATLABSystem: '<S2>/SinkBlock'

  Pub_Ackermann_01_191.publish(&rtDW.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(rtM)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S8>/In1'
    //   MATLABSystem: '<S5>/SourceBlock'

    varargout_1 = Sub_Ackermann_01_205.getLatestMessage(&rtDW.varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S8>/Enable'

    if (varargout_1) {
      rtDW.In1 = rtDW.varargout_2;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Product: '<S7>/Product2' incorporates:
    //   Gain: '<S7>/1//L'

    rtDW.psidotrads = (real_T)(rtP.uL_Gain * rtDW.In1.Speed) *
      rtDW.In1.SteeringAngle;

    // Gain: '<S7>/Gain'
    rtDW.L2psidot = rtP.vehicle_length / 2.0 * rtDW.psidotrads;
  }

  // Trigonometry: '<S7>/Trigonometric Function1' incorporates:
  //   Integrator: '<S7>/Integrator2'

  rtb_sincos_o1_idx_0 = sin(rtX.Integrator2_CSTATE);

  // Trigonometry: '<S7>/Trigonometric Function' incorporates:
  //   Integrator: '<S7>/Integrator2'

  rtb_sincos_o2_idx_0 = cos(rtX.Integrator2_CSTATE);

  // Sum: '<S7>/Sum' incorporates:
  //   Product: '<S7>/Product1'
  //   Product: '<S7>/Product3'

  rtDW.v_Xms = rtDW.In1.Speed * rtb_sincos_o2_idx_0 - rtDW.L2psidot *
    rtb_sincos_o1_idx_0;

  // Sum: '<S7>/Sum1' incorporates:
  //   Product: '<S7>/Product'
  //   Product: '<S7>/Product4'

  rtDW.v_Yms = rtDW.In1.Speed * rtb_sincos_o1_idx_0 + rtDW.L2psidot *
    rtb_sincos_o2_idx_0;
  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      // Update absolute timer for sample time: [0.1s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.1, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      rtM->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void Ackermann_01_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->ModelData.derivs);

  // Derivatives for Integrator: '<S7>/Integrator2'
  _rtXdot->Integrator2_CSTATE = rtDW.psidotrads;

  // Derivatives for Integrator: '<S7>/Integrator'
  _rtXdot->Integrator_CSTATE = rtDW.v_Xms;

  // Derivatives for Integrator: '<S7>/Integrator1'
  _rtXdot->Integrator1_CSTATE = rtDW.v_Yms;
}

// Model initialize function
void Ackermann_01_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **)
                         &rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->ModelData.intgData.y = rtM->ModelData.odeY;
  rtM->ModelData.intgData.f[0] = rtM->ModelData.odeF[0];
  rtM->ModelData.intgData.f[1] = rtM->ModelData.odeF[1];
  rtM->ModelData.intgData.f[2] = rtM->ModelData.odeF[2];
  rtM->ModelData.contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->ModelData.intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.1;

  {
    static const char_T tmp[15] = { '/', 'a', 'c', 'k', 'e', 'r', 'm', 'a', 'n',
      'n', '_', 'd', 'a', 't', 'a' };

    static const char_T tmp_0[9] = { '/', 's', 'i', 'm', '_', 'p', 'o', 's', 'e'
    };

    char_T tmp_1[16];
    char_T tmp_2[10];
    int32_T i;

    // Start for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    rtDW.obj.isInitialized = 0;
    rtDW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      tmp_2[i] = tmp_0[i];
    }

    tmp_2[9] = '\x00';
    Pub_Ackermann_01_191.createPublisher(tmp_2, MessageQueueLen);

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of Start for SubSystem: '<Root>/Publish'

    // Start for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S5>/SourceBlock'
    rtDW.obj_f.isInitialized = 0;
    rtDW.obj_f.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      tmp_1[i] = tmp[i];
    }

    tmp_1[15] = '\x00';
    Sub_Ackermann_01_205.createSubscriber(tmp_1, MessageQueueLen);

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Start for SubSystem: '<Root>/Subscribe'

    // InitializeConditions for Integrator: '<S7>/Integrator2'
    rtX.Integrator2_CSTATE = rtP.yaw_ic;

    // InitializeConditions for Integrator: '<S7>/Integrator'
    rtX.Integrator_CSTATE = rtP.X_ic;

    // InitializeConditions for Integrator: '<S7>/Integrator1'
    rtX.Integrator1_CSTATE = rtP.Y_ic;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S8>/Out1'
    rtDW.In1 = rtP.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
