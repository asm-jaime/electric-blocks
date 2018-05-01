#include "gen_sin.h"

void exec_gen_sin(gen_sin *v) {
  // Compute the angle rate
  v->Angle += _IQmpy(v->StepAngleMax, v->Freq);

  // Saturate the angle rate within (-1,1)
  if (v->Angle>_IQ(1.0)) {
    v->Angle -= _IQ(1.0);
  } else if (v->Angle < _IQ(-1.0)) {
    v->Angle += _IQ(1.0);
  }

  v->Out = _IQmpy(_IQsinPU(v->Angle), v->Ampl) + v->Offset;
}
