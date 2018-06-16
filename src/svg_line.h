#ifndef SVG_LINE_H
#define SVG_LINE_H
class SvgLine : public SvgShape{
public:
  SvgLine(double x1, double y1, double x2, double y2) :_x1(x1), _y1(y1), _x2(x2), _y2(y2){

  }

  std::string toSVG() const{

  }
private:
  double _x1, _y1, _x2, _y2;
};
#endif
