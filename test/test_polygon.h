#include "../src/vector.h"
#include "../src/polygon.h"
#include "../src/dot.h"

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
TEST(PolygonTest, centroid){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  double v4[] = {0,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector vertices[] = {A,B,C,D};
  Vector O = centroid(vertices,4);
  ASSERT_EQ(1.5,O.at(1));
  ASSERT_EQ(2,O.at(2));
}

TEST(PolygonTest, rectangleAreaOne){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  double v4[] = {0,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector vertices[] = {A,B,C,D};
  Vector O = centroid(vertices,4);
  Polygon p(vertices,4);
  ASSERT_EQ(12,p.area());
  ASSERT_EQ(14,p.length());
}

TEST(PolygonTest, rectangleAreaTwo){
  double v1[] = {0,0};
  double v2[] = {3,4};
  double v3[] = {3,0};
  double v4[] = {0,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector vertices[] = {A,B,C,D};
  Vector O = centroid(vertices,4);
  Vector R = A-O;
  bubbleSort(vertices,vertices+4,
    [&](Vector u,Vector v){return angle(R,u-O)>angle(R,v-O);}
  );
  Polygon p(vertices,4);
  ASSERT_EQ(12,p.area());
  ASSERT_EQ(14,p.length());
}
