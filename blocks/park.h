#ifndef PARK_H_
#define PARK_H_

#include "IQMathLib.h"
#include "dmctype.h"

typedef struct park {
  _iq Alpha;      // Input: stationary d-axis stator variable
  _iq Beta;       // Input: stationary q-axis stator variable
  _iq Angle;      // Input: rotating angle (pu)
  _iq Ds;         // Output: rotating d-axis stator variable
  _iq Qs;         // Output: rotating q-axis stator variable
  void (*exec)(); // Pointer to calculation function
} park;

#define park_def { 0, \
                   0, \
                   0, \
                   0, \
                   0, \
                   (void (*)(Uint32))exec_park, \
}

void exec_park(park *v);

#endif // PARK_H_
