#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#define MaxOfShoppingCart 50
#include "./book.h"
class ShoppingCart{
public:
  ShoppingCart(){
    _numberOfItems = 0;
    _bs = new Book [MaxOfShoppingCart];
  }

  ShoppingCart(Book const *bs, int numberOfItems){
    _numberOfItems = numberOfItems;
    _bs = new Book [_numberOfItems];
    for(int i=0;i<_numberOfItems;i++){
      _bs[i] = bs[i];
    }
  }

  ShoppingCart(ShoppingCart const &sc){
    _numberOfItems = sc._numberOfItems;
    _bs = new Book [sc._numberOfItems];
    for(int i=0;i<_numberOfItems;i++){
      _bs[i] = sc._bs[i];
    }
  }

  ~ShoppingCart(){
    delete [] _bs;
  }

  void add(Book const &k){
    _numberOfItems++;
    for(int i=0;i<_numberOfItems;i++){
      if(_bs[i].title() == k.title()){
        std::string error("You have already put this book into shoppingcart");
        throw error;
      }
      else{
        _bs[_numberOfItems] = k;
        break;
      }
    }
  }

  void del(Book const &k){
    int i;
    for(i=0;i<MaxOfShoppingCart;i++){
      if(_bs[i].title() == k.title()){
        _numberOfItems--;
        Book temp("","",0);
        _bs[i] = temp;
        break;
      }
    }
    if(i == MaxOfShoppingCart){
      std::string error("You dont have this book in the shhoppingcart.");
      throw error;
    }
  }

  int numberOfItems() const{
    return _numberOfItems;
  }

  Book getBookByTitle(std::string const &s){
    for(int i=0;i<MaxOfShoppingCart;i++){
      if(_bs[i].title() == s){
        return _bs[i];
      }
    }
    std::string error("You dont have this book in the shhoppingcart.");
    throw error;
  }

  int totalOfPrice(){
    int totalPrice;
    for(int i=0;i<=_numberOfItems;i++){
      totalPrice += _bs[i].price();
    }
    return totalPrice;
  }

private:
  Book * _bs;
  int _numberOfItems;
};
#endif
