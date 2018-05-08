#ifndef TEST_POLYNOMIAL_H
#define TEST_POLYNOMIAL_H
#include "../src/term.h"
#include "../src/polynomial.h"

TEST(polynomial,polynomialConstructor){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term ts[3] = {a,b,c};
  Polynomial p(ts,3,4);
  ASSERT_EQ(4,p.degreeOfPolynomial());
}

TEST(polynomial,polynomialCopyAssignment){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term ts[3] = {a,b,c};
  Polynomial p1(ts,3,4);
  Polynomial p2;
  p2 = p1;
  ASSERT_EQ(4,p2.degreeOfPolynomial());
}

TEST(polynomial,polynomialTerm){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term ts[3] = {a,b,c};
  Polynomial p(ts,3,4);
  Term temp= p.term(4);
  ASSERT_EQ(3,temp.coefficient());
  ASSERT_EQ(4,temp.exponent());
}

TEST(polynomial,polynomialTermNoExist){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term ts[3] = {a,b,c};
  Polynomial p(ts,3,4);
  Term temp= p.term(5);
  ASSERT_EQ(0,temp.coefficient());
  ASSERT_EQ(5,temp.exponent());
}

TEST(polynomial,polynomialMultipleByTerm){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term d(2,2);
  Term ts[3] = {a,b,c};
  Polynomial p(ts,3,4);
  p.multiplyByTerm(d);
  ASSERT_EQ(6,p.degreeOfPolynomial());
}

TEST(polynomial,polynomialMultipleByZero){
  Term a(1,2);
  Term b(2,3);
  Term c(3,4);
  Term d(0,4);
  Term ts[3] = {a,b,c};
  Polynomial p(ts,3,4);
  p.multiplyByTerm(d);
  ASSERT_EQ(0,p.degreeOfPolynomial());
}

TEST(polynomial,polynomialOperatorPlusOne){
  Term p1(1,2);
  Term p2(2,3);
  Term p3(3,6);
  Term q1(1,2);
  Term q2(2,3);
  Term q3(3,4);
  Term ts1[3] = {p1,p2,p3};
  Term ts2[3] = {q1,q2,q3};
  Polynomial p(ts1,3,6);
  Polynomial q(ts2,3,4);
  p = p+q;
  ASSERT_EQ(6,p.degreeOfPolynomial());
}

TEST(polynomial,polynomialOperatorPlusTwo){
  Term p1(1,2);
  Term p2(-2,3);
  Term p3(3,4);
  Term q1(1,2);
  Term q2(2,3);
  Term q3(3,6);
  Term ts1[3] = {p1,p2,p3};
  Term ts2[3] = {q1,q2,q3};
  Polynomial p(ts1,3,4);
  Polynomial q(ts2,3,6);
  p = p+q;
  ASSERT_EQ(6,p.degreeOfPolynomial());
  ASSERT_EQ(0,p.term(3).coefficient());
  ASSERT_EQ(3,p.term(4).coefficient());
  ASSERT_EQ(3,p.term(6).coefficient());
}
#endif
