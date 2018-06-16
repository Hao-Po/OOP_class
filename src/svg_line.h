#ifndef SVG_LINE_H
#define SVG_LINE_H
#include "./svg_shape.h"
using namespace std;
class SvgLine : public SvgShape{
public:
  SvgLine(double x1, double y1, double x2, double y2)
    : SvgShape(1), _x1(x1), _y1(y1), _x2(x2), _y2(y2){}

  std::string toSVG() const{
    return string ("<line x1=\"" + to_string(_x1) + "\" y1=\"" + to_string(_y1) + "\" x2=\"" +
           to_string(_x2) + "\" y2=\"" + to_string(_y2) + "\" stroke-width=\"" + to_string(_strokeWidth) +
           "\" stroke=\"" + _strokeColor + "\" fill=\"" + _fillColor + "\"/>");
  }


private:
  double _x1, _y1, _x2, _y2;
};
#endif
