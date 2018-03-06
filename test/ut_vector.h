#include "../src/vector.h"


// TEST (VectorAddTwoDimension, ) {
//     double u[] = {1, 2};
//     double v[] = {3, 4};
//     double* sum = add(u, v, 2, 2);
//     ASSERT_EQ(4, sum[0]);
//     ASSERT_EQ(6, sum[1]);
// }

TEST (LengthTwoDimensions, ) {
    double v[] = {7, 24};
    ASSERT_EQ(25, length(v, 2));
}

TEST (LengthMultiDimensions, ) {
    double v[] = {1, 2, 3, 4, 5};
    ASSERT_NEAR(7.416198, length(v, 5), 0.00001);
}

TEST (Angle, ) {
    double v[] = {1, 1};
    double u[] = {1, 0};
    ASSERT_NEAR(3.14159625/4, angle(v, 2, u, 2), 0.0001);
}

TEST (AngleBiggerThanHelfPI, ) {
    double v[] = {-1, 1};
    double u[] = {1, 0};
    ASSERT_NEAR(3.14159625 * 3 / 4, angle(v, 2, u, 2), 0.0001);
}

TEST (AngleMultiDimensions, ) {
    double v[] = {1, 0, 0};
    double u[] = {1, 0, 1};
    ASSERT_NEAR(3.14159625/4, angle(v, 3, u, 3), 0.0001);
}

TEST (Area, ) {
    double v[] = {3, 0};
    double u[] = {3, 4};

    ASSERT_NEAR(6, area(v, 2, u, 2), 0.00001);
}

TEST (AreaMultiDimension, ) {
    double v[] = {1, 1, 0};
    double u[] = {1, 1, 1};
    std::cout << area(v, 3, u, 3) << std::endl;
    printf("\n\n\n");
    ASSERT_NEAR(1.0/1.414, area(v, 3, u, 3), 0.001);
}

// TEST(Vector, InnerProductIllegalDimException) {
//   double a[] = {1, 1, 1};
//   double b[] = {2, 1};
//   ASSERT_THROW(innerProduct(a,b,3,2), std::string);
// }
//
// TEST(Vector, InnerProduct) {
//   double a[] = {1, 1};
//   double b[] = {2, 1};
//   double ip = innerProduct(a,b,2,2);
//   ASSERT_EQ(3,ip);
// }
//
// TEST(Vector, InnerProductPair) {
//   Point a = std::make_pair(1,1);
//   Point b = std::make_pair(2,1);
//   double ip = innerProduct(a,b);
//   ASSERT_EQ(3,ip);
// }
//
// TEST(Vector, create) {
//   double a[] = {1, 0};
//   Vector v(a, 2);
//   ASSERT_EQ(1, v.at(1));
//   ASSERT_EQ(0, v.at(2));
//   ASSERT_EQ(2, v.dim());
// }
//
// TEST(Vector, InnerProductVector) {
//   double a[] = {1, 1};
//   Vector u(a, 2);
//   double b[] = {2, 1};
//   Vector v(b, 2);
//
//   double ip = innerProduct(u,v);
//   ASSERT_EQ(3,ip);
// }
