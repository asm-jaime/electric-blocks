#include <stdio.h>

#include "unity.h"
#include "clarke.h"


void setUp(void){}

void tearDown(void){}

void test_clarke(void){
  clarke clarke_test = clarke_def;
  clarke_test.As = 400;
  clarke_test.Bs = 900;

  clarke_test.exec(&clarke_test);
  //printf("A: %ld, B: %ld", clarke_test.Alpha, clarke_test.Beta);
  //TEST_ASSERT_EQUAL_UINT(30, add_simple.Out);
}
