#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include "./book.h"
#include <map>
using namespace std;

class ShoppingCart{
public:
  ShoppingCart(){
    _numberOfItems = 0;
  }

  ShoppingCart(Book const *bs, int numberOfItems) : _numberOfItems(numberOfItems){
    for(int i=0;i<_numberOfItems;i++){
      _bs[i] = bs[i];
    }
  }

  void add(Book const &k){
    for(auto it=_bs.begin();it!=_bs.end();it++){
      if(it->second.title() == k.title()){
        std::string error("You have already put this book into shoppingcart");
        throw error;
      }
    }
    _bs.insert(pair<int,Book>(_bs.size(),k)) ;
  }

  void del(Book const &k){
    auto it=_bs.begin();
    for(;it!=_bs.end();it++){
      if(it->second.title() == k.title()){
        _bs.erase(it);
        break;
      }
    }
    if(it == _bs.end()){
      std::string error("You dont have this book in the shhoppingcart.");
      throw error;
    }
  }

  int numberOfItems() const{
    return _bs.size();
  }

  Book getBookByTitle(std::string const &s){
    for(auto it=_bs.begin();it!=_bs.end();it++){
      if(it->second.title() == s){
        return it->second;
      }
    }
    std::string error("You dont have this book in the shhoppingcart.");
    throw error;
  }

  int totalOfPrice(){
    double result = 0;
    for(auto it=_bs.begin();it!=_bs.end();it++){
      result += it->second.price();
    }
    return result;
  }
private:
  map<int,Book> _bs;
  int _numberOfItems;
};
#endif
