#include "../src/vector.h"

// TEST(Vector, InnerProductUndefined) {
//   double a[] = {1, 1, 1};
//   double b[] = {2, 1};
//   double ip = innerProduct(a,b,3,2);
//   ASSERT_EQ(3, ip);
// }

TEST (Vector, add) {
  ASSERT_EQ(20, add(2,3));
}

TEST(Vector, InnerProductIllegalDimException) {
  double a[] = {1, 1, 1};
  double b[] = {2, 1};
  ASSERT_THROW(innerProduct(a,b,3,2), std::string);
}

TEST(Vector, InnerProduct) {
  double a[] = {1, 1};
  double b[] = {2, 1};
  double ip = innerProduct(a,b,2,2);
  ASSERT_EQ(3,ip);
}

TEST(Vector, InnerProductPair) {
  Point a = std::make_pair(1,1);
  Point b = std::make_pair(2,1);
  double ip = innerProduct(a,b);
  ASSERT_EQ(3,ip);
}

TEST(Vector, create) {
  double a[] = {1, 0};
  Vector v(a, 2);
  ASSERT_EQ(1, v.at(1));
  ASSERT_EQ(0, v.at(2));
  ASSERT_EQ(2, v.dim());
}

TEST(Vector, InnerProductVector) {
  double a[] = {1, 1};
  Vector u(a, 2);
  double b[] = {2, 1};
  Vector v(b, 2);

  double ip = innerProduct(u,v);
  ASSERT_EQ(3,ip);
}
