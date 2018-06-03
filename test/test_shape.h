#ifndef TEST_SHAPE_H
#define TEST_SHAPE_H
#include "../src/vector.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/polygon.h"
TEST (ShapeTest, CircleArea) {
  double r = 3;
  double a[] = {0,0};
  Vector o(a,2);
  Shape * s = new Circle(o,r);
  ASSERT_NEAR(9*M_PI, s->area(), 0.0001);
  ASSERT_NEAR(6*M_PI, s->length(), 0.0001);
}

TEST(ShapeTest, PolygonArea){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  Vector a( v1, 2);
  Vector b( v2, 2);
  Vector c( v3, 2);
  Vector vertices[] = {a,b,c};
  Shape * s = new Polygon(vertices, 3);
  ASSERT_EQ(6,s->area());
}

TEST(ShapeTest, SortingArrayArea){
  double r = 3;
  double a[] = {0,0};
  Vector o(a,2);
  Shape * BigCircle = new Circle(o,3);
  Shape * SmallCircle = new Circle(o,1);
  double b[] = {0, 1};
  double c[] = {1, 1};
  double d[] = {1, 0};
  Vector v1 (b, 2);
  Vector v2 (c, 2);
  Vector v3 (d, 2);
  Vector vertices[] = {o,v1,v2,v3};
  Shape * SmallSquare = new Polygon(vertices, 4);
  double e[] = {0,4};
  double f[] = {4,4};
  double g[] = {4,0};
  Vector v4 (e,2);
  Vector v5 (f,2);
  Vector v6 (g,2);
  Vector vv[] = {o,v4,v5,v6};
  Shape * BigSquare = new Polygon(vv,4);
  Shape * s [] ={BigCircle,SmallSquare,BigSquare,SmallCircle};
  bubbleSort(s,s+4,[](Shape * s1, Shape * s2){
    return s1->area() > s2->area();
  });
  ASSERT_EQ(SmallSquare,s[0]);
  ASSERT_EQ(SmallCircle,s[1]);
  ASSERT_EQ(BigSquare,s[2]);
  ASSERT_EQ(BigCircle,s[3]);
}

#endif
