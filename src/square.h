#ifndef SQUARE_H
#define SQUARE_H
#include "./shape.h"
class Square : public Shape{
public:
  Square(double s){
    _s = s;
  }

  double area() const{
    return _s*_s;
  }

  double length() const{
    return 4*_s;
  }
private:
  double _s;
};

#endif
