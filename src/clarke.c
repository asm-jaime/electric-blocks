#include "clarke.h"

void exec_clarke(clarke *v) {
  v->Alpha = v->As;
  v->Beta = _IQmpy((v->As + _IQmpy(_IQ(2),v->Bs)), _IQ(0.57735026918963));
}
