#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H
class SvgCircle : public SvgShape{
public:
  SvgCircle(double x, double y, double r) : SvgShape(), _x(x), _y(y), _r(r){

  }

  std::string toSVG() const{

  }
private:
  double _x, _y, _z;
};
#endif
