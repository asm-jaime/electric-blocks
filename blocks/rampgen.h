#ifndef RAMPGEN_H_
#define RAMPGEN_H_


#include "IQMathLib.h"
#include "dmctype.h"

typedef struct rampgen {
  _iq Freq;         // Input: Ramp frequency (pu)
  _iq StepAngleMax; // Parameter: Maximum step angle (pu)
  _iq Angle;        // Variable: Step angle (pu)
  _iq Gain;         // Input: Ramp gain (pu)
  _iq Offset;       // Input: Ramp offset (pu)
  _iq Out;          // Output: Ramp signal (pu)
  void (*exec)();   // Pointer to calculation function
} rampgen;

#define rampgen_def { 0, \
                      0, \
                      0, \
                      _IQ(1), \
                      _IQ(1), \
                      0, \
                      (void (*)(Uint32))exec_rampgen, \
}

void exec_rampgen(rampgen *v);

#endif // RAMPGEN_H_
