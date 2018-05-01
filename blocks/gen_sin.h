#ifndef GEN_SIN_H_
#define GEN_SIN_H_


#include "IQMathLib.h"
#include "dmctype.h"

typedef struct gen_sin {
  _iq Freq;         // Input: Ramp frequency (pu)
  _iq StepAngleMax; // Parameter: Maximum step angle (pu)
  _iq Angle;        // Variable: Step angle (pu)
  _iq Ampl;         // Input: Amplitude sin (pu)
  _iq Offset;       // Input: y-axis offset (pu)
  _iq Out;          // Output: sine signal (pu)
  void (*exec)();   // Pointer to calculation function
} gen_sin;

#define gen_sin_def { 0, \
                      0, \
                      0, \
                      _IQ(1), \
                      0, \
                      0, \
                      (void (*)(Uint32))exec_gen_sin, \
}

void exec_gen_sin(gen_sin *v);

#endif // GEN_SIN_H_
