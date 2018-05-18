#include "../src/bubblesort.h"
#include "../src/template.h"

TEST(bubblesort, integerAscending){
  int a[] = {2,3,1,4,5};
  bubbleSort(a,a+5,GreaterThan<int>);
  ASSERT_EQ(1,a[0]);
  ASSERT_EQ(3,a[2]);
  ASSERT_EQ(5,a[4]);
}

TEST(bubblesort, _float){
  double a[] = {2.1,3.1,1.1,4.1,5.1};
  bubbleSort(a,a+5,GreaterThan<double>);
  ASSERT_EQ(1.1,a[0]);
  ASSERT_EQ(3.1,a[2]);
  ASSERT_EQ(5.1,a[4]);
}

TEST(bubblesort, lambda){
  double a[] = {2.1,3.1,1.1,4.1,5.1};
  bubbleSort(a,a+5,
    [&] (double a,double b){return a>b;}
  );
  ASSERT_EQ(1.1,a[0]);
  ASSERT_EQ(3.1,a[2]);
  ASSERT_EQ(5.1,a[4]);
}
