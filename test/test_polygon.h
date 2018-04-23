#include "../src/vector.h"
#include "../src/polygon.h"
TEST(PolygonTest, constructPolygon){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector vertices[] = {A,B,C};
  Polygon p(vertices,3);
  ASSERT_EQ(0,p.vertex(1).at(1));
  ASSERT_EQ(0,p.vertex(1).at(2));
}

TEST(PolygonTest, triangleArea){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector vertices[] = {A,B,C};
  Polygon p(vertices,3);
  ASSERT_EQ(6,p.area());
}

TEST(PolygonTest, rectangleArea){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  double v4[] = {0,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector vertices[] = {A,B,C,D};
  Polygon p(vertices,4);
  ASSERT_EQ(12,p.area());
}
