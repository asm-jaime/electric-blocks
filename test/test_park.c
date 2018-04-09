#include <stdio.h>

#include "unity.h"
#include "park.h"

void setUp(void){}

void tearDown(void){}

void test_park(void){
  park park_test = park_def;
  park_test.Alpha = 0.5;
  park_test.Beta = 0.8;
  park_test.Angle = 0.4;

  park_test.exec(&park_test);
  printf("park in: Alpha: %f, Beta: %f", park_test.Alpha, park_test.Beta);
  printf("park out: Ds: %f, Qs: %f", park_test.Ds, park_test.Qs);
  //TEST_ASSERT_EQUAL_UINT(30, add_simple.Out);
}
