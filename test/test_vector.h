#include "../src/vector.h"

TEST(vector, CopyAssignment){
  double a[] = {2,3};
  Vector u(a,2);
  Vector v;
  v = u;
  ASSERT_EQ(2,v.at(1));
  ASSERT_EQ(3,v.at(2));
}

TEST(vector, triangleArea){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  double arc = triangleArea(A,B,C);
  ASSERT_EQ(6,arc);
}
