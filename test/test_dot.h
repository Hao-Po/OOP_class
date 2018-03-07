#include "../src/dot.h"

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
