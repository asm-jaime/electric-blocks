#include "clarke.h"
#include "iqmathlib.h"

void Init(void) {
}

void Exec(clarke * v) {
  v->Alpha = v->As;
  v->Beta = _IQmpy((v->As + _IQmpy(_IQ(2),v->Bs)), _IQ(0.57735026918963));
}
