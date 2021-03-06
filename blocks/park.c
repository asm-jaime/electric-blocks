#include "park.h"

void exec_park(park *v) {
  _iq cosa = _IQcosPU(v->Angle);
  _iq sina = _IQsinPU(v->Angle);

  v->Ds = _IQmpy(v->Alpha, cosa) + _IQmpy(v->Beta, sina);
  v->Qs = _IQmpy(v->Beta, cosa) - _IQmpy(v->Alpha, sina);
}
