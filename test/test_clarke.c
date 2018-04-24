#include <stdio.h>

#include "unity.h"
#include "clarke.h"


void setUp(void){}

void tearDown(void){}

void test_clarke(void){

  // ========== test default clarke
  clarke clarke_test = clarke_def;
  clarke_test.As = 400;
  clarke_test.Bs = 900;
  clarke_test.exec(&clarke_test);
  printf("for As: %f, Bs: %f\n", clarke_test.As, clarke_test.Bs);
  printf("res Alpha: %f, Beta: %f\n", clarke_test.Alpha, clarke_test.Beta);

  // ========== test pointer clarke
  clarke *p_clarke = (clarke *)malloc(1*sizeof(clarke));
  p_clarke->As = 400;
  p_clarke->Bs = 900;
  p_clarke->exec = exec_clarke;
  p_clarke->exec(p_clarke);
  printf("for As: %f, Bs: %f\n", clarke_test.As, clarke_test.Bs);
  printf("res Alpha: %f, Beta: %f\n", clarke_test.Alpha, clarke_test.Beta);
  free(p_clarke);

  //TEST_ASSERT_EQUAL_UINT(30, add_simple.Out);
}
