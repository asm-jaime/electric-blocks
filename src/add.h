#ifndef ADD_H
#define ADD_H

#include "IQMathLib.h"
#include "dmctype.h"

typedef struct add {
  _iq Out;
  _iq In1;
  _iq In2;
  void (*init)();
  void (*exec)();
} add;

#define add_def { 0, \
                  0, \
                  0, \
                  (void(*)(Uint32))Init, \
                  (void(*)(Uint32))Exec, \
}

void Init(void);
void Exec(add *v);

#endif
