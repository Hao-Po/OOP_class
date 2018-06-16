#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include "./shape.h"
#include "./vector.h"
class Circle: public Shape{
public:
  static Circle * create(double x, double y, double r){
    double o[] = {x,y};
    Vector v(o,2);
    return new Circle (v,r);
  }

  Circle(Vector &o,double r) : _o(o),_r(r){}

  double area() const{
    return M_PI*_r*_r;
  }

  double length() const{
    return 2*M_PI*_r;
  }

private:
  Vector _o;
  double _r;
};
#endif
