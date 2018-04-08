#include <stdio.h>

#include "unity.h"
#include "add.h"


void setUp(void){}

void tearDown(void){}

void test_add(void){
  add add_simple = add_def;
  add_simple.In1 = 10;
  add_simple.In2 = 20;

  add_simple.exec(&add_simple);
  TEST_ASSERT_EQUAL_UINT(30, add_simple.Out);
}
