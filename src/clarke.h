#ifndef __CLARKE_H__
#define __CLARKE_H__

#include "iqmathlib.h"
#include "dmctype.h"

typedef struct clarke {
          _iq As;        // Input: phase-a stator variable
          _iq Bs;        // Input: phase-b stator variable
          _iq Alpha;     // Output: stationary d-axis stator variable
          _iq Beta;      // Output: stationary q-axis stator variable
          void (*init)();// Pointer to init function
          void (*exec)();// Pointer to calculation function
         } clarke;

#define clarke_def { 0, \
                     0, \
                     0, \
                     0, \
                     (void (*)(Uint32))Init, \
                     (void (*)(Uint32))Exec, \
}

void Init(void);
void Exec(clarke *v);

#endif // __CLARKE_H__
