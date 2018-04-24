#include <stdint.h>
#include <stdlib.h>

#include "add.h"
#include "clarke.h"
#include "park.h"
#include "ipark.h"
#include "pid_reg3.h"
#include "rampgen.h"
#include "rmp_cntl.h"
#include "speed_meas_qep.h"
#include "svgen_dq.h"

#if defined(WIN32) || defined(_WIN32)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

EXPORT add *init_add(void){
  add *p_add = (add *)malloc(sizeof(add));
  p_add->A = 0.0;
  p_add->B = 0.0;
  p_add->Out = 0.0;
  p_add->exec = exec_add;
  return p_add;
}

EXPORT clarke *init_clarke(void){
  clarke *p_clarke = (clarke *)malloc(sizeof(clarke));
  p_clarke->As = 0.0;
  p_clarke->Bs = 0.0;
  p_clarke->Alpha = 0.0;
  p_clarke->Beta = 0.0;
  p_clarke->exec = exec_clarke;
  return p_clarke;
}

EXPORT park *init_park(void){
  park *p_park = (park *)malloc(sizeof(park));
  p_park->Alpha = 0.0;
  p_park->Beta = 0.0;
  p_park->Angle = 0.0;
  p_park->Ds = 0.0;
  p_park->Qs = 0.0;

  p_park->exec = exec_park;
  return p_park;
}

EXPORT ipark *init_ipark(void){
  ipark *p_ipark = (ipark *)malloc(sizeof(ipark));
  p_ipark->Alpha = 0.0;
  p_ipark->Beta = 0.0;
  p_ipark->Angle = 0.0;
  p_ipark->Ds = 0.0;
  p_ipark->Qs = 0.0;

  p_ipark->exec = exec_ipark;
  return p_ipark;
}

EXPORT pid_reg3 *init_pid_reg3(void){
  pid_reg3 *p_pid_reg3 = (pid_reg3 *)malloc(sizeof(pid_reg3));
  p_pid_reg3->Ref = 0;
  p_pid_reg3->Fdb = 0;
  p_pid_reg3->Err = 0;
  p_pid_reg3->Kp = 1.3;
  p_pid_reg3->Up = 0;
  p_pid_reg3->Ui = 0;
  p_pid_reg3->Ud = 0;
  p_pid_reg3->OutPreSat = 0;
  p_pid_reg3->OutMax = 1;
  p_pid_reg3->OutMin = -1;
  p_pid_reg3->Out = 0;
  p_pid_reg3->SatErr = 0;
  p_pid_reg3->Ki = 0.2;
  p_pid_reg3->Kc = 0.5;
  p_pid_reg3->Kd = 1.05;
  p_pid_reg3->Up1 = 0;

  p_pid_reg3->exec = exec_pid_reg3;
  return p_pid_reg3;
}

EXPORT rampgen *init_rampgen(void){
  rampgen *p_rampgen = (rampgen *)malloc(sizeof(rampgen));
  p_rampgen->Freq = 0;
  p_rampgen->StepAngleMax = 0;
  p_rampgen->Angle = 0;
  p_rampgen->Gain = 1;
  p_rampgen->Out = 0;
  p_rampgen->Offset = 1;

  p_rampgen->exec = exec_rampgen;
  return p_rampgen;
}

EXPORT rmp_cntl *init_rmp_cntl(void){
  rmp_cntl *p_rmp_cntl = (rmp_cntl *)malloc(sizeof(rmp_cntl));
  p_rmp_cntl->TargetValue = 0;
  p_rmp_cntl->RampDelayMax = 40;
  p_rmp_cntl->RampLowLimit = -1;
  p_rmp_cntl->RampHighLimit = 1;
  p_rmp_cntl->RampDelayCount = 0;
  p_rmp_cntl->SetpointValue = 0;
  p_rmp_cntl->EqualFlag = 0;

  p_rmp_cntl->exec = exec_rmp_cntl;
  return p_rmp_cntl;
}

EXPORT speed_meas_qep *init_speed_meas_qep(void){
  speed_meas_qep *p_speed_meas_qep = (speed_meas_qep *)malloc(sizeof(speed_meas_qep));
  p_speed_meas_qep->ElecTheta = 0;
  p_speed_meas_qep->DirectionQep = 1;
  p_speed_meas_qep->OldElecTheta = 0;
  p_speed_meas_qep->Speed = 0;
  p_speed_meas_qep->BaseRpm = 0;
  p_speed_meas_qep->K1 = 0;
  p_speed_meas_qep->K2 = 0;
  p_speed_meas_qep->K3 = 0;
  p_speed_meas_qep->SpeedRpm = 0;

  p_speed_meas_qep->exec = exec_speed_meas_qep;
  return p_speed_meas_qep;
}

EXPORT svgen_dq *init_svgen_dq(void){
  svgen_dq *p_svgen_dq = (svgen_dq *)malloc(sizeof(svgen_dq));
  p_svgen_dq->Ualpha = 0;
  p_svgen_dq->Ubeta = 0;
  p_svgen_dq->Ta = 0;
  p_svgen_dq->Tb = 0;
  p_svgen_dq->Tc = 0;

  p_svgen_dq->exec = exec_svgen_dq;
  return p_svgen_dq;
}

EXPORT void free_block(void *block){
  free(block);
}
