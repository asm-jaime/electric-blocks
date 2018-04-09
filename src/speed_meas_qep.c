#include "speed_meas_qep.h"

void Exec(speedfr *v) {
   _iq Tmp1;

  // Differentiator
  // Synchronous speed computation
  if ((v->ElecTheta < _IQ(0.9))&(v->ElecTheta > _IQ(0.1))) {
      Tmp1 = _IQmpy(v->K1,(v->ElecTheta - v->OldElecTheta));
  } else {
    Tmp1 = _IQtoIQ21(v->Speed);
  }

  // Low-pass filter
  Tmp1 = _IQmpy(v->K2,_IQtoIQ21(v->Speed))+_IQmpy(v->K3,Tmp1);

  if (Tmp1 > _IQ21(1)){
    v->Speed = _IQ(1);
  } else if (Tmp1 < _IQ21(-1)) {
    v->Speed = _IQ(-1);
  } else {
    v->Speed = _IQ21toIQ(Tmp1);
  }

  // Update the electrical angle
  v->OldElecTheta = v->ElecTheta;

  // Change motor speed from pu value to rpm value (GLOBAL_Q -> Q0)
  // Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q
  v->SpeedRpm = _IQmpy(v->BaseRpm,v->Speed);
}
