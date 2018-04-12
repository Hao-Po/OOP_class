#ifndef TEST_FRACTION_H
#define TEST_FRACTION_H

#include <algorithm>

#include "../src/fraction.h"
#include "../src/gcd.h"

TEST (Fraction, ConstructorWithNoParameter) {
    Fraction f;
    ASSERT_EQ(0,f.numerator());
    ASSERT_EQ(1,f.denominator());
    ASSERT_EQ('+',f.sign());
}

TEST(Fraction, ConstructorWithOneParameter) {
    Fraction f(3);
    ASSERT_EQ(3, f.numerator());
    ASSERT_EQ(1, f.denominator());
    ASSERT_EQ('+', f.sign());

    Fraction g(-7);
    ASSERT_EQ(7, g.numerator());
    ASSERT_EQ(1, g.denominator());
    ASSERT_EQ('-', g.sign());
}

TEST (Fraction, ConstructorWithTwoParameter) {
    Fraction f(1,3);
    ASSERT_EQ(1,f.numerator());
    ASSERT_EQ(3,f.denominator());
    ASSERT_EQ('+',f.sign());

    Fraction g(-1,3);
    ASSERT_EQ(1,g.numerator());
    ASSERT_EQ(3,g.denominator());
    ASSERT_EQ('-',g.sign());

    Fraction h(-1,-3);
    ASSERT_EQ(1,h.numerator());
    ASSERT_EQ(3,h.denominator());
    ASSERT_EQ('+',h.sign());

    Fraction i(1, -3);
    ASSERT_EQ(1, i.numerator());
    ASSERT_EQ(3, i.denominator());
    ASSERT_EQ('-', i.sign());
}

TEST (Fraction, ConstructorException) {
    ASSERT_ANY_THROW(Fraction h(1, 0));
}

TEST(Fraction, str) {
    Fraction f(-1, 3);
    ASSERT_EQ(std::string("-1/3"), f.str());
    Fraction g(-1, -3);
    ASSERT_EQ(std::string("1/3"), g.str());
    Fraction h(3, 1);
    ASSERT_EQ(std::string("3"), h.str());
    Fraction i(3, -1);
    ASSERT_EQ(std::string("-3"), i.str());
    Fraction j(0, 3);
    ASSERT_EQ(std::string("0"), j.str());
}

TEST (Fraction, gcd) {
    ASSERT_EQ(1,gcd(3,7));
    ASSERT_EQ(1,gcd(-3,7));
    ASSERT_EQ(3,gcd(3,9));
    ASSERT_EQ(1,gcd(1,9));
    ASSERT_EQ(9,gcd(9,9));
}

TEST(Fraction, OperationAdd) {
    Fraction f(1, 3);
    Fraction g(2, -4);
    Fraction h = f + g;
    ASSERT_EQ(1, h.numerator());
    ASSERT_EQ(6, h.denominator());
    ASSERT_EQ('-', h.sign());
    ASSERT_EQ(std::string("-1/6"), h.str());
}

TEST (sortingLT, Fraction) {
    Fraction a(0);
    Fraction b(-1);
    Fraction c(-2,-3);
    Fraction d(2,4);
    Fraction e(1,3);

    Fraction fs[5]={a,b,c,d,e};
    std::sort(fs,fs+5,FractionLT);
    for (int i = 0; i < 5; i++) {
        std::cout << fs[i].str() <<std::endl;
    }
    ASSERT_EQ(std::string("-1"), fs[0].str());
    ASSERT_EQ(std::string("0"), fs[1].str());
    ASSERT_EQ(std::string("1/3"), fs[2].str());
    ASSERT_EQ(std::string("2/4"), fs[3].str());
    ASSERT_EQ(std::string("2/3"), fs[4].str());
}

TEST (lsortingGT, Fraction) {
    Fraction a;
    Fraction b(-1);
    Fraction c(-2,-3);
    Fraction d(2,4);
    Fraction e(1,3);

    Fraction fs[5]={a,b,c,d,e};
    std::sort(fs,fs+5,FractionGT);

    ASSERT_EQ(std::string("-1"), fs[4].str());
    ASSERT_EQ(std::string("0"), fs[3].str());
    ASSERT_EQ(std::string("1/3"), fs[2].str());
    ASSERT_EQ(std::string("2/4"), fs[1].str());
    ASSERT_EQ(std::string("2/3"), fs[0].str());
}
#endif
