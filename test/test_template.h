#ifndef TEST_TEMPLATE_H
#define TEST_TEMPLATE_H
#include "../src/template.h"

TEST(templateTest, swapInt){
  int a=1,b=2;
  change<int>(a,b);
  ASSERT_EQ(2,a);
  ASSERT_EQ(1,b);
}

TEST(templateTest, swapDouble){
  double a=1.2,b=2.3;
  change<double>(a,b);
  ASSERT_EQ(2.3,a);
  ASSERT_EQ(1.2,b);
}

TEST(templateTest, fillTestOne){
  int a[8] = {0};
  fill<int>(a,8,5);
  ASSERT_EQ(5,a[5]);
  ASSERT_EQ(5,a[7]);
}

TEST(templateTest, fillTestTwo){
  double a[8] = {0};
  fill<double>(a,8,4.367);
  ASSERT_EQ(4.367,a[1]);
  ASSERT_EQ(4.367,a[7]);
}

TEST(templateTest, reverseTestOne){
  int a[] = {1,2,3,4,5};
  reverse<int>(a,5);
  ASSERT_EQ(5,a[0]);
  ASSERT_EQ(3,a[2]);
  ASSERT_EQ(1,a[4]);
}

TEST(templateTest, reverseTestTwo){
  double a[] = {1.1,2.2,3.3,4.4,5.5,6.6};
  reverse<double>(a,6);
  ASSERT_EQ(6.6,a[0]);
  ASSERT_EQ(5.5,a[1]);
  ASSERT_EQ(4.4,a[2]);
  ASSERT_EQ(3.3,a[3]);
  ASSERT_EQ(2.2,a[4]);
  ASSERT_EQ(1.1,a[5]);
}

TEST(templateTest, deepCopyOne){
  int a[] = {1,2,3,4,5};
  deepCopy<int>(a,5);
  ASSERT_EQ(1,a[0]);
  ASSERT_EQ(3,a[2]);
  ASSERT_EQ(5,a[4]);
}

TEST(templateTest, deepCopyTwo){
  double a[] = {1.1,2.2,3.3,4.4,5.5};
  deepCopy<double>(a,5);
  ASSERT_EQ(1.1,a[0]);
  ASSERT_EQ(3.3,a[2]);
  ASSERT_EQ(5.5,a[4]);
}
#endif
