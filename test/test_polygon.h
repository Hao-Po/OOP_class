#include "../src/vector.h"
#include "../src/polygon.h"
TEST (PolygonTest, constructPolygon){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vertor vertices[] = {A,B,C};
  Polygon p(vertices,3);
  ASSERT_EQ(0,p.vertex(1).at(1));
  ASSERT_EQ(0,p.vertex(1).at(2));
}
