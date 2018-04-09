#include "rmp_cntl.h"

void Exec(rmp_cntl *v) {
  _iq tmp;
  tmp = v->TargetValue - v->SetpointValue;

  if (_IQabs(tmp) > _IQ(0.0000305)) {
    v->RampDelayCount += 1;
    if (v->RampDelayCount >= v->RampDelayMax) {
      if (v->TargetValue >= v->SetpointValue) {
        v->SetpointValue += _IQ(0.0000305);  // 0.0000305 is resolution of Q15
        if (v->SetpointValue > v->RampHighLimit) {
          v->SetpointValue = v->RampHighLimit;
        }
        v->RampDelayCount = 0;
      } else {
       v->SetpointValue -= _IQ(0.0000305);   // 0.0000305 is resolution of Q15
       if (v->SetpointValue < v->RampLowLimit) {
         v->SetpointValue = v->RampLowLimit;
       }
       v->RampDelayCount = 0;
      }
    }
  }
  else {
    v->EqualFlag = 0x7FFFFFFF;
  }
}
