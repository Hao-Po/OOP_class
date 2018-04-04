#include "../src/vector.h"

TEST(DotProduct, Vectorfirst){
  double u[] = {1,1};
  double v[] = {0,1};
  Vector x(u,2);
  Vector y(v,2);
  double dp=dotProduct(x,y);
  ASSERT_EQ(1,dp);
}

TEST (DotProduct, second) {
  double u[] = {1,1,0};
  double v[] = {0,1,1};
  Vector x(u,3);
  Vector y(v,3);
  double dp = dotProduct(x,y);
  ASSERT_EQ(1, dp);
}

TEST (DotProduct, third) {
  double u[] = {1,0};
  double v[] = {1,1,1};
  Vector x(u,2);
  Vector y(v,3);
  ASSERT_ANY_THROW(dotProduct(x,y));
}

TEST (angleProduct, first){
  double u[]={1,0};
  double v[]={1,1};
  Vector x(u,2);
  Vector y(v,2);
  double ap=angle(x,y);
  ASSERT_NEAR(M_PI/4,ap,0.0001);
}

TEST (angleProduct, second){
  double u[]={3,0};
  double v[]={-1,1};
  Vector x(u,2);
  Vector y(v,2);
  double ap=angle(x,y);
  ASSERT_NEAR(M_PI*3/4,ap,0.0001);
}

TEST (areaProduct, first){
  double u[]={1,0};
  double v[]={1,1};
  Vector x(u,2);
  Vector y(v,2);
  double rp=area(x,y);
  ASSERT_NEAR(0.5,rp,0.0001);
}

TEST (areaProduct, second){
  double u[]={3,0};
  double v[]={-1,1};
  Vector x(u,2);
  Vector y(v,2);
  double rp=area(x,y);
  ASSERT_NEAR(1.5,rp,0.0001);
}

TEST (addProduct, first){
  double u[]={1,0};
  double v[]={1,1};
  Vector x(u,2);
  Vector y(v,2);
  ASSERT_EQ(2,add(x,y)->at(1));
  ASSERT_EQ(1,add(x,y)->at(2));
}

TEST (addProduct, second){
  double u[]={1,0,5};
  double v[]={1,8,6};
  Vector x(u,3);
  Vector y(v,3);
  ASSERT_EQ(2,add(x,y)->at(1));
  ASSERT_EQ(8,add(x,y)->at(2));
  ASSERT_EQ(11,add(x,y)->at(3));
}
