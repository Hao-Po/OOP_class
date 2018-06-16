#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H
#include "./svg_shape.h"
using namespace std;
class SvgCircle : public SvgShape {
public:
  SvgCircle(double x, double y, double r)
    : SvgShape(), _x(x), _y(y), _r(r){}

  std::string toSVG() const{
    return string ("<circle cx=\"" + to_string(_x) + "\" cy=\"" + to_string(_y) +
           "\" r=\"" + to_string(_r) + "\" stroke-width=\"" + to_string(_strokeWidth) +
           "\" stroke=\"" + _strokeColor + "\" fill=\"" + _fillColor + "\"/>");
  }
private:
  double _x, _y, _r;
};
#endif
