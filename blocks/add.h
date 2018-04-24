#ifndef ADD_H_
#define ADD_H_

#include "IQMathLib.h"
#include "dmctype.h"

typedef struct add {
  _iq A;
  _iq B;
  _iq Out;
  void (*exec)();
} add;

#define add_def { 0, \
                  0, \
                  0, \
                  (void(*)(Uint32))exec_add, \
}

void exec_add(add *v);

#endif
