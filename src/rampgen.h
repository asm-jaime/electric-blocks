#ifndef __RAMPGEN_H__
#define __RAMPGEN_H__


#include "iqmathlib.h"
#include "dmctype.h"

typedef struct rampgen {
            _iq  Freq;          // Input: Ramp frequency (pu)
            _iq  StepAngleMax;  // Parameter: Maximum step angle (pu)
            _iq  Angle;         // Variable: Step angle (pu)
            _iq  Gain;          // Input: Ramp gain (pu)
            _iq  Out;           // Output: Ramp signal (pu)
            _iq  Offset;        // Input: Ramp offset (pu)
            void (*init)();     // Pointer to init function
            void (*exec)();     // Pointer to calculation function
         } rampgen;

#define rampgen_def { 0, \
                      0, \
                      0, \
                      _IQ(1), \
                      0, \
                      _IQ(1), \
                      (void (*)(Uint32))Init, \
                      (void (*)(Uint32))Exec, \
}

void Init(rampgen *v);
void Exec(rampgen *v);

#endif // __RAMPGEN_H__
