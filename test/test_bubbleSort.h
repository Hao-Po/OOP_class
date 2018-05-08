#include "../src/bubbleSort.h"

TEST(bubbleSort, integerAscending){
  int a[] = {2,3,1,4,5};
  bubbleSort(a,a+5,GreaterThan<int>);
  ASSERT_EQ(1,a[0]);
  ASSERT_EQ(3,a[2]);
  ASSERT_EQ(5,a[4]);
}

TEST(bubbleSort, _float){
  double a[] = {2.1,3.1,1.1,4.1,5.1};
  bubbleSort(a,a+5,GreaterThan<double>);
  ASSERT_EQ(1.1,a[0]);
  ASSERT_EQ(3.1,a[2]);
  ASSERT_EQ(5.1,a[4]);
}

TEST(bubbleSort, swapInt){
  int a=1,b=2;
  change<int>(a,b);
  ASSERT_EQ(2,a);
  ASSERT_EQ(1,b);
}

TEST(bubbleSort, swapDouble){
  double a=2.75,b=3.11;
  change<double>(a,b);
  ASSERT_EQ(3.11,a);
  ASSERT_EQ(2.75,b);
}
