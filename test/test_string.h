// #include "../src/vector_io.h"
//
// TEST (string, string) {
//   std::string cpps="hello, string!";
//   int i = 3;
//   int j(3);
//   ASSERT_EQ('h', cpps[0]);
//   ASSERT_EQ('!', cpps[13]);
//   ASSERT_EQ('\0', cpps[14]);
//   ASSERT_EQ(14, cpps.length());
// }
//
// TEST (string, pullVectorFromString) {
//   std::string s = "            2 [1,2]";
//   Vector *vec;
//   vec = pullVectorFromString(s);
//   //ASSERT_EQ(2, vec->_dim);
//   ASSERT_NEAR(1, vec->at(1), 0.001);
//   ASSERT_NEAR(2, vec->at(2), 0.001);
//   delete [] vec;
// }
// //
// // TEST (string, pullVectorFromString_2) {
// //   std::string s = "3 [1,2,3]";
// //   int dim;
// //   double* a = pullVectorFromString(s, &dim);
// //   ASSERT_EQ(3, dim);
// //   ASSERT_NEAR(1, a[0], 0.001);
// //   ASSERT_NEAR(2, a[1], 0.001);
// //   ASSERT_NEAR(3, a[2], 0.001);
// //   delete [] a;
// // }
// //
// // TEST (string, pullVectorFromString_3) {
// //   std::string s = "2 [1,2";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
// //
// // TEST (string, pullVectorFromString_4) {
// //   std::string s = "] [1,2]";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
// //
// // TEST (string, pullVectorFromString_5) {
// //   std::string s = "-5 [1,2]";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
// //
// // TEST (string, pullVectorFromString_6) {
// //   std::string s = "1.5 [1,2]";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
// //
// // TEST (string, pullVectorFromString_7) {
// //   std::string s = "2 ]1,2]";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
// //
// // TEST (string, pullVectorFromString_8) {
// //   std::string s = "2 [1]";
// //   int dim;
// //   ASSERT_ANY_THROW(pullVectorFromString(s, &dim));
// // }
