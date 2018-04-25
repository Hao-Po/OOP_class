#ifndef TEST_TERM_H
#define TEST_TERM_H
#include "../src/term.h"

TEST(term, termCopy){
  Term a(5,2);
  ASSERT_EQ(5,a.coefficient());
  ASSERT_EQ(2,a.exponent());
}

TEST(term, equalToOne){
  Term a(5,2);
  Term b(5,2);
  ASSERT_EQ(1,a == b);
}

TEST(term, equalToTwo){
  Term a(5,2);
  Term b(4,2);
  ASSERT_EQ(0,a == b);
}

TEST(term, equalToThree){
  Term a(5,2);
  Term b(5,5);
  ASSERT_EQ(0,a == b);
}

TEST(term, multiplyOne){
  Term a(5,2);
  Term b(4,2);
  Term c;
  c = a*b;
  ASSERT_EQ(20,c.coefficient());
  ASSERT_EQ(4,c.exponent());
}

TEST(term, multiplyTwo){
  Term a(5,2);
  Term b(-4,8);
  Term c;
  c = a*b;
  ASSERT_EQ(-20,c.coefficient());
  ASSERT_EQ(10,c.exponent());
}

TEST(term, multiplyThree){
  Term a(5,2);
  Term b(-4,0);
  Term c;
  c = a*b;
  ASSERT_EQ(-20,c.coefficient());
  ASSERT_EQ(2,c.exponent());
}

TEST(term, isZeroTrue){
  Term a;
  Term b(0,8);
  ASSERT_EQ(1,a.isZero());
  ASSERT_EQ(1,b.isZero());
}

TEST(term, isZeroFalse){
  Term a(5,2);
  Term b(5,0);
  ASSERT_EQ(0,a.isZero());
  ASSERT_EQ(0,b.isZero());
}
#endif
