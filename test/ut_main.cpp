// #include <gtest/gtest.h>
// #include <string>
//
// #include "ut_vector.h"
// int main( int argc , char **argv )
// {
//     testing :: InitGoogleTest( &argc , argv ) ;
//     return RUN_ALL_TESTS( ) ;
// }
#include <stdio.h>
#include <assert.h>
#include "../src/dot.h"
#include "./test_dot.h"

int main(int argc, char **argv) {
  printf("Hello, dot product!\n");

  testDotProduct();
  testDotProduct_2();
  testDotProduct_3();
}
