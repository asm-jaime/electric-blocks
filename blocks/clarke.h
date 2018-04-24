#ifndef CLARKE_H_
#define CLARKE_H_

#include "IQMathLib.h"
#include "dmctype.h"

typedef struct clarke {
  _iq As;         // Input: phase-a stator variable
  _iq Bs;         // Input: phase-b stator variable
  _iq Alpha;      // Output: stationary d-axis stator variable
  _iq Beta;       // Output: stationary q-axis stator variable
  void (*exec)(); // Pointer to calculation function
} clarke;

#define clarke_def { 0, \
                     0, \
                     0, \
                     0, \
                     (void (*)(Uint32))exec_clarke, \
}

void exec_clarke(clarke *v);

#endif // CLARKE_H_
