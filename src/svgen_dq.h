#ifndef __SVGEN_DQ_H__
#define __SVGEN_DQ_H__


#include "iqmathlib.h"
#include "dmctype.h"

typedef struct svgendq {
          _iq  Ualpha;    // Input: reference alpha-axis phase voltage
          _iq  Ubeta;     // Input: reference beta-axis phase voltage
          _iq  Ta;        // Output: reference phase-a switching function
          _iq  Tb;        // Output: reference phase-b switching function
          _iq  Tc;        // Output: reference phase-c switching function
          void (*init)(); // Pointer to init function
          void (*exec)(); // Pointer to calculation function
        } svgendq;

#define svgendq_def { 0, \
                      0, \
                      0, \
                      0, \
                      0, \
                      (void (*)(Uint32))Init, \
                      (void (*)(Uint32))Exec, \
}

void Exec(ipark *v);
void Init(ipark *v);

#endif // __SVGEN_DQ_H__
