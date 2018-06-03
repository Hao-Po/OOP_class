#ifndef TEST_PRISM_H
#define TEST_PRISM_H
#include <cmath>
#include "../src/vector.h"
#include "../src/circle.h"
#include "../src/polygon.h"
#include "../src/shape.h"
#include "../src/prism.h"

TEST(PrismTest, triangle){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector a(v1, 2);
  Vector b(v2, 2);
  Vector c(v3, 2);
  Vector vertices[] = {a,b,c};
  Shape *s = new Polygon(vertices, 3);
  Prism p(s,5);
  ASSERT_EQ(5,p.height());
  ASSERT_EQ(30,p.volume());
  ASSERT_EQ(72,p.surfaceArea());
}

TEST(PrismTest, rectangle){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {0,4};
  double v4[] = {3,4};
  Vector a(v1, 2);
  Vector b(v2, 2);
  Vector c(v3, 2);
  Vector d(v4, 2);
  Vector vertices[] = {a,b,c,d};
  Vector O = centroid(vertices,4);
  Vector R = a-O;
  bubbleSort(vertices,vertices+4,
    [&](Vector u,Vector v){return angle(R,u-O)>angle(R,v-O);}
  );
  Shape *s = new Polygon(vertices, 4);
  Prism p(s,3);
  ASSERT_EQ(3,p.height());
  ASSERT_EQ(36,p.volume());
  ASSERT_EQ(66,p.surfaceArea());
}

TEST(PrismTest, circle){
  double a[] = {0,0};
  Vector o(a,2);
  Shape *s = new Circle(o,3);
  Prism p(s,6);
  ASSERT_EQ(6,p.height());
  ASSERT_NEAR(54*M_PI,p.volume(),0.0001);
  ASSERT_NEAR(18*M_PI+6*M_PI*6,p.surfaceArea(),0.0001);
}
#endif
