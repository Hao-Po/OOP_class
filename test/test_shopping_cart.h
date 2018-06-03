#ifndef TEST_SHOPPING_CART_H
#define TEST_SHOPPING_CART_H
#include "../src/book.h"
#include "../src/shopping_cart.h"
TEST (ShoppingCart, add) {
    ShoppingCart sc;
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    Book k2("Object-Oriented Programming", "Patrick", 1108);
    sc.add(k1);
    ASSERT_EQ(1, sc.numberOfItems());
    ASSERT_ANY_THROW(sc.add(k2));
}

TEST (ShoppingCart, getBookByTitle) {
    ShoppingCart sc;
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    sc.add(k1);
    Book k2("Design Patterns", "YCC", 1500);
    sc.add(k2);
    Book result = sc.getBookByTitle("Design Patterns");
    ASSERT_EQ("Design Patterns", result.title());
    ASSERT_EQ("YCC", result.author());
    ASSERT_EQ(1500, result.price());
    ASSERT_ANY_THROW(sc.getBookByTitle("hello"));
}

TEST (Book, normal) {
    Book k("Object-Oriented Programming", "Patrick", 1108);
    ASSERT_EQ("Object-Oriented Programming", k.title());
    ASSERT_EQ("Patrick", k.author());
    ASSERT_EQ(1108, k.price());
}

TEST (ShoppingCart, del) {
    ShoppingCart sc;
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    Book k2("Object-Oriented Programming", "Patrick", 1108);
    Book k3("Design Patterns", "YCC", 1500);
    sc.add(k1);
    sc.del(k2);
    ASSERT_EQ(0, sc.numberOfItems());
    ASSERT_ANY_THROW(sc.del(k3));
}

TEST(ShoppingCart, constructWithArray) {
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    Book k2("Design Patterns", "YCC", 1500);
    Book bs[] = {k1, k2};

    ShoppingCart sc(bs, 2);
    ASSERT_EQ(2, sc.numberOfItems());
}

TEST (Book, equal) {
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    Book k2("Object-Oriented Programming", "Patrick", 1108);
	  Book k3("Design Patterns", "YCC", 1500);
    ASSERT_TRUE(k1 == k2);
  	ASSERT_FALSE(k1 == k3);
}

TEST(ShoppingCart, totalOfPrice) {
    ShoppingCart sc;
    Book k1("Object-Oriented Programming", "Patrick", 1108);
    sc.add(k1);
    Book k2("Design Patterns", "YCC", 1500);
    sc.add(k2);
    ASSERT_EQ(2608, sc.totalOfPrice());
}
#endif
