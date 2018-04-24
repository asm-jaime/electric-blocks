#include <stdint.h>
#include <stdlib.h>

#include "clarke.h"

#if defined(WIN32) || defined(_WIN32)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

EXPORT clarke *init_clarke(void){
  clarke *p_clarke = (clarke *)malloc(1*sizeof(clarke));
  p_clarke->As = 0.0;
  p_clarke->Bs = 0.0;
  p_clarke->Alpha = 0.0;
  p_clarke->Beta = 0.0;
  p_clarke->exec = exec_clarke;
  return p_clarke;
}

EXPORT void free_block(void *block){
  free(block);
}
