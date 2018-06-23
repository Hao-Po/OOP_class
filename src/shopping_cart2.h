#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include "./book.h"
#include <vector>
using namespace std;

class ShoppingCart{
public:
  ShoppingCart(){
    _numberOfItems = 0;
  }

  ShoppingCart(Book const *bs, int numberOfItems) : _numberOfItems(numberOfItems){
    for(int i=0;i<_numberOfItems;i++){
      _bs.push_back(bs[i]);
    }
  }

  void add(Book const &k){
    for(auto it=_bs.begin();it!=_bs.end();it++){
      if(it->title() == k.title()){
        std::string error("You have already put this book into shoppingcart");
        throw error;
      }
    }
    _bs.push_back(k);
    _numberOfItems++;
  }

  void del(Book const &k){
    for(auto it = _bs.begin();it!=_bs.end();it++){
      if(it->title() == k.title()){
        _bs.erase(it);
        _numberOfItems--;
        return;
      }
    }
    std::string error("You dont have this book in the shhoppingcart.");
    throw error;
  }

  int numberOfItems() const{
    return _numberOfItems;
  }

  Book getBookByTitle(std::string const &s){
    for(auto it=_bs.begin();it!=_bs.end();it++){
      if(it->title() == s){
        return *it;
      }
    }
    std::string error("You dont have this book in the shhoppingcart.");
    throw error;
  }

  int totalOfPrice(){
    double result = 0;
    for(auto it=_bs.begin();it!=_bs.end();it++){
      result += it->price();
    }
    return result;
  }
private:
  int _numberOfItems;
  vector<Book> _bs;
};
#endif
