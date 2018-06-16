#ifndef COMBO_H
#define COMBO_H
#include "./shape.h"
#include <list>
#include <algorithm>
class Combo : public Shape{
public:
  double area() const{
    double result = 0;
    for(Shape * i:_component){
      result += i->area();
    }
    return result;
  }

  double length() const{
    double result = 0;
    for(Shape * i:_component){
      result += i->length();
    }
    return result;
  }

  void add(Shape *s){
    _component.push_back(s);
  }

  void remove(Shape *s){
    auto it = std::find(_component.begin(),_component.end(),s);
    if(it == _component.end()){
      throw std::string("Not found");
    }
    _component.erase(it);
  }

private:
  std::list<Shape*> _component;
};
#endif
