#ifndef __PIDREG3_H__
#define __PIDREG3_H__

// ========== anti-widup pid regulator

#include "iqmathlib.h"
#include "dmctype.h"

typedef struct pidreg3 {
          _iq  Ref;       // Input: Reference input
          _iq  Fdb;       // Input: Feedback input
          _iq  Err;       // Variable: Error
          _iq  Kp;        // Parameter: Proportional gain
          _iq  Up;        // Variable: Proportional output
          _iq  Ui;        // Variable: Integral output
          _iq  Ud;        // Variable: Derivative output
          _iq  OutPreSat; // Variable: Pre-saturated output
          _iq  OutMax;    // Parameter: Maximum output
          _iq  OutMin;    // Parameter: Minimum output
          _iq  Out;       // Output: PID output
          _iq  SatErr;    // Variable: Saturated difference
          _iq  Ki;        // Parameter: Integral gain
          _iq  Kc;        // Parameter: Integral correction gain
          _iq  Kd;        // Parameter: Derivative gain
          _iq  Up1;       // History: Previous proportional output
          void (*init)(); // Pointer to init function
          void (*exec)(); // Pointer to calculation function
         } pidreg3;


#define pidreg3_def { 0, \
                      0, \
                      0, \
                      _IQ(1.3), \
                      0, \
                      0, \
                      0, \
                      0, \
                      _IQ(1), \
                      _IQ(-1), \
                      0, \
                      0, \
                      _IQ(0.02), \
                      _IQ(0.5), \
                      _IQ(1.05), \
                      0, \
                      (void (*)(Uint32))Init, \
                      (void (*)(Uint32))Exec, \
}

void Init(pidreg3 *v);
void Exec(pidreg3 *v);

#endif // __PIDREG3_H__
