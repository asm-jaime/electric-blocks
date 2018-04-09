#ifndef __IPARK_H__
#define __IPARK_H__


#include "iqmathlib.h"
#include "dmctype.h"

typedef struct ipark {
          _iq  Alpha;     // Output: stationary d-axis stator variable
          _iq  Beta;      // Output: stationary q-axis stator variable
          _iq  Angle;     // Input: rotating angle (pu)
          _iq  Ds;        // Input: rotating d-axis stator variable
          _iq  Qs;        // Input: rotating q-axis stator variable
          void (*init)(); // Pointer to init function
          void (*exec)(); // Pointer to calculation function
         } ipark;

#define ipark_def { 0, \
                    0, \
                    0, \
                    0, \
                    0, \
                    (void (*)(Uint32))Init, \
                    (void (*)(Uint32))Exec, \
}

void Exec(ipark *v);
void Init(ipark *v);

#endif // __IPARK_H__
