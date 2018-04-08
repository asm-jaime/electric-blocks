#ifndef __PARK_H__
#define __PARK_H__

#include "iqmathlib.h"
#include "dmctype.h"

typedef struct park {
          _iq  Alpha;     // Input: stationary d-axis stator variable
          _iq  Beta;      // Input: stationary q-axis stator variable
          _iq  Angle;     // Input: rotating angle (pu)
          _iq  Ds;        // Output: rotating d-axis stator variable
          _iq  Qs;        // Output: rotating q-axis stator variable
          void (*init)(); // Pointer to init function
          void (*exec)(); // Pointer to calculation function
         } park;

#define park_def { 0, \
                   0, \
                   0, \
                   0, \
                   0, \
                   (void (*)(Uint32))Init, \
                   (void (*)(Uint32))Exec, \
}

void Init(void);
void Exec(park *v);

#endif // __PARK_H__
