//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "Ackermann_01.h"
#include "Ackermann_01_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"

// Function prototype declaration
void exitTask(int sig);
void terminateTask(void *arg);
void baseRateTask(void *arg);
void subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested(rtM);
  while (runModel) {
    sem_wait(&baserateTaskSem);
    Ackermann_01_step();

    // Get model outputs here
    runModel = (rtmGetErrorStatus(rtM) == (NULL)) && !rtmGetStopRequested(rtM);
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(rtM, "stopping the model");
}

void terminateTask(void *arg)
{
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  {
    int ret;
    runModel = 0;
  }

  // Disable rt_OneStep() here
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(rtM, 0);

  // Initialize model
  Ackermann_01_initialize();

  // Call RTOS Initialization funcation
  myRTOSInit(0.1, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
