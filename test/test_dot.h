#include "../src/dot.h"
#include <math.h>

TEST (DotProduct, first) {
  double u[] = {1,1};
  double v[] = {0,1};
  double dp = dotProduct(u, 2, v, 2);
  ASSERT_EQ(1, dp);
}

TEST (DotProduct, second) {
  double u[] = {1,1,0};
  double v[] = {0,1,1};
  double dp = dotProduct(u, 3, v, 3);
  ASSERT_EQ(1, dp);
}

TEST (DotProduct, third) {
  double u[] = {1,0};
  double v[] = {1,1,1};
  ASSERT_ANY_THROW(dotProduct(u, 2, v, 3));
}

TEST (lengthProduct, first) {
  double v[]={1,1};
  double lp=length(v,2);
  ASSERT_EQ(sqrt(2),lp);
}

TEST (lengthProduct, second) {
  double v[]={1,1,5};
  double lp=length(v,3);
  ASSERT_EQ(sqrt(27),lp);
}

TEST (angleProduct, first){
  double u[]={1,0};
  double v[]={1,1};
  double ap=angle(u,2,v,2);
  ASSERT_NEAR(M_PI/4,ap,0.0001);
}

TEST (angleProduct, second){
  double u[]={3,0};
  double v[]={-1,1};
  double ap=angle(u,2,v,2);
  ASSERT_NEAR(M_PI*3/4,ap,0.0001);
}

TEST (angleProduct, third){
  double u[]={3,0};
  double v[]={-1,1,0};
  ASSERT_ANY_THROW(angle(u,2,v,3));
}

TEST (areaProduct, first){
  double u[]={1,0};
  double v[]={1,1};
  double rp=area(u,2,v,2);
  ASSERT_NEAR(0.5,rp,0.0001);
}

TEST (areaProduct, second){
  double u[]={3,0};
  double v[]={-1,1};
  double rp=area(u,2,v,2);
  ASSERT_NEAR(1.5,rp,0.0001);
}

TEST (areaProduct, third){
  double u[]={3,0};
  double v[]={-1,1,0};
  ASSERT_ANY_THROW(area(u,2,v,3));
}
