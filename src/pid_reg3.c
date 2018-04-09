#include "pid_reg3.h"

void Init(pidreg3 *v) {
}

void Exec(pidreg3 *v) {
  // Compute the error
  v->Err = v->Ref - v->Fdb;

  // Compute the proportional output
  v->Up = _IQmpy(v->Kp, v->Err);

  // Compute the integral output
  v->Ui = v->Ui + _IQmpy(v->Ki, v->Up) + _IQmpy(v->Kc, v->SatErr);

  // Compute the derivative output
  v->Ud = _IQmpy(v->Kd, (v->Up - v->Up1));

  // Compute the pre-saturated output
  v->OutPreSat = v->Up + v->Ui + v->Ud;

  // Saturate the output
  if (v->OutPreSat > v->OutMax) {
    v->Out = v->OutMax;
  } else if (v->OutPreSat < v->OutMin) {
    v->Out = v->OutMin;
  } else {
    v->Out = v->OutPreSat;
  }

  // Compute the saturate difference
  v->SatErr = v->Out - v->OutPreSat;

  // Update the previous proportional output
  v->Up1 = v->Up;
}
