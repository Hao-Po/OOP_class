#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H
#include <iostream>
#include <fstream>
#include "../src/vector_io.h"
#include "../src/vector.h"
#include "../src/dot.h"
#include "../src/polygon.h"
#include "../src/bubblesort.h"
TEST(mainfunction, fileOpen){
  fstream file;
  file.open("test/test.txt");
  ASSERT_EQ(1,file.is_open());
  file.close();
}

TEST(mainfunction, makeVectorFromStringOne){
  std::string s("(1,0)");
  Vector v = *makeVectorFromString(s);
  ASSERT_EQ(1,v.at(1));
  ASSERT_EQ(0,v.at(2));
}

TEST(mainfunction, makeVectorFromStringTwo){
  std::string s("(-2,7)");
  Vector v = *makeVectorFromString(s);
  ASSERT_EQ(-2,v.at(1));
  ASSERT_EQ(7,v.at(2));
}

TEST(mainfunction, centroidOfFourPoints){
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

TEST(mainfunction, centroidOfSixPoints){
  double v1[] = {0,3};
  double v2[] = {2,0};
  double v3[] = {4,0};
  double v4[] = {6,3};
  double v5[] = {4,6};
  double v6[] = {2,6};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector E(v5,2);
  Vector F(v6,2);
  Vector vertices[] = {A,B,C,D,E,F};
  Vector O = centroid(vertices,6);
  ASSERT_EQ(3,O.at(1));
  ASSERT_EQ(3,O.at(2));
}

TEST(mainfunction, angle){
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
  Vector R = A-O;
  ASSERT_EQ(0,angle(R,A-O));
  ASSERT_EQ(M_PI,angle(R,C-O));
}

TEST(mainfunction, bubblesort){
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
  ASSERT_EQ(0,vertices[0].at(1));
  ASSERT_EQ(0,vertices[0].at(2));
  ASSERT_EQ(3,vertices[1].at(1));
  ASSERT_EQ(0,vertices[1].at(2));
  ASSERT_EQ(3,vertices[2].at(1));
  ASSERT_EQ(4,vertices[2].at(2));
  ASSERT_EQ(0,vertices[3].at(1));
  ASSERT_EQ(4,vertices[3].at(2));
}

TEST(mainfunction, createPolygon){
  double v1[] = {0,0};
  double v2[] = {3,0};
  double v3[] = {3,4};
  double v4[] = {0,4};
  Vector A(v1,2);
  Vector B(v2,2);
  Vector C(v3,2);
  Vector D(v4,2);
  Vector vertices[] = {A,B,C,D};
  Polygon p = createPolygon(vertices,4);
  ASSERT_EQ(0,p.vertex(1).at(1));
  ASSERT_EQ(0,p.vertex(1).at(2));
  ASSERT_EQ(3,p.vertex(2).at(1));
  ASSERT_EQ(0,p.vertex(2).at(2));
  ASSERT_EQ(3,p.vertex(3).at(1));
  ASSERT_EQ(4,p.vertex(3).at(2));
  ASSERT_EQ(0,p.vertex(4).at(1));
  ASSERT_EQ(4,p.vertex(4).at(2));
}

TEST(mainfunction, lengthAndAreaOfPolygon){
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

TEST(mainfunction, setprecision){
  double x=1.2235;
  double y=2;
  std::cout << fixed << setprecision(2) << x << endl;
  std::cout << y << endl;
}
#endif
