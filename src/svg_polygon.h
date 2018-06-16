#ifndef SVG_POLYGON_H
#define SVG_POLYGON_H
#include <sstream>
#include "./svg_shape.h"
using namespace std;
class SvgPolygon : public SvgShape{
public:
  SvgPolygon(std::vector<double *> const & v)
    : SvgShape(), _v(v){}

  std::string toSVG() const{
    string s = "<polygon points=\"";
    for(int i=0;i<_v.size()-1;i++){
      for(int j=0;j<2;j++){
        s += to_string(_v[i][j]);
        s += " ";
      }
    }
    s += to_string(_v[_v.size()-1][0]) + " " + to_string(_v[_v.size()-1][1]) +
         "\" stroke-width=\"" + to_string(_strokeWidth) + "\" stroke=\"" + _strokeColor +
         "\" fill=\"" + _fillColor + "\"/>";
    return s;
  }
private:
  std::vector<double *> _v;
};

#endif
