#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "./shape.h"
class Circle: public Shape{
public:
  Circle(Vector &o,double r){
    _o = o;
    _r = r;
  }

  double area(){
    return M_PI*_r*_r;
  }

  double length(){
    return 2*M_PI*_r;
  }

private:
  Vector _o;
  double _r;
};
#endif
