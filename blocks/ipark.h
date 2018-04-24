#ifndef IPARK_H_
#define IPARK_H_


#include "IQMathLib.h"
#include "dmctype.h"

typedef struct ipark {
  _iq Alpha;      // Output: stationary d-axis stator variable
  _iq Beta;       // Output: stationary q-axis stator variable
  _iq Angle;      // Input: rotating angle (pu)
  _iq Ds;         // Input: rotating d-axis stator variable
  _iq Qs;         // Input: rotating q-axis stator variable
  void (*exec)(); // Pointer to calculation function
} ipark;

#define ipark_def { 0, \
                    0, \
                    0, \
                    0, \
                    0, \
                    (void (*)(Uint32))exec_ipark, \
}

void exec_ipark(ipark *v);

#endif // IPARK_H_
