#ifndef PRISM_H
#define PRISM_H
#include "./shape.h"

class Prism{
public:
  Prism(Shape *s, double h){
    _h = h;
    _s = s;
  }

  double volume() const{
    return _s->area() * _h;
  }

  double height() const{
    return _h;
  }

  double surfaceArea() const{
    return _s->length()*_h + _s->area()*2;
  }

private:
  Shape *_s;
  double _h;
};
#endif
