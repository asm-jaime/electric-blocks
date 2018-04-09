#include "ipark.h"

void Exec(ipark *v) {
  _iq sina = _IQsinPU(v->Angle);
  _iq cosa = _IQcosPU(v->Angle);

  v->Alpha = _IQmpy(v->Ds, cosa) - _IQmpy(v->Qs, sina);
  v->Beta = _IQmpy(v->Qs, cosa) + _IQmpy(v->Ds, sina);
}


