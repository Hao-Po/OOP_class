#ifndef TEST_SHAPE_H
#define TEST_SHAPE_H
#include "../src/vector.h"
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/polygon.h"
#include "../src/square.h"
#include "../src/combo.h"
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

TEST(ShapeTest, Factory){
  Circle *c = Circle::create(1,-1,1);
  ASSERT_EQ(M_PI,c->area());
}

TEST(ShapeTest, Car){
  Circle *c1 = Circle::create(1,-1,1);
  Circle *c2 = Circle::create(3,-1,1);
  double a[] = {0,0};
  double b[] = {4,0};
  double c[] = {4,2};
  double d[] = {0,2};
  Vector vertices[] = {Vector(a,2), Vector(b,2), Vector(c,2), Vector(d,2)};
  Polygon *p = createPolygon(vertices,4);
  Square *s = new Square(2);
  Combo combo;
  combo.add(c1);
  combo.add(c2);
  combo.add(p);
  combo.add(s);
  ASSERT_EQ(2 * M_PI + 12,combo.area());
  ASSERT_EQ(4 * M_PI + 20,combo.length());
  combo.remove(c1);
  ASSERT_EQ(M_PI + 12,combo.area());
  ASSERT_EQ(2 * M_PI + 20,combo.length());
  ASSERT_ANY_THROW(combo.remove(c1));

}

#endif
