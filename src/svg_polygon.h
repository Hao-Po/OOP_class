#ifndef SVG_POLYGON_H
#define SVG_POLYGON_H
class SvgPolygon : public SvgShape{
public:
  SvgPolygon(std::vector<double *> const & v) : SvgShape(), _v(v){

  }

  std::string toSVG() const{

  }
private:
  std::vector<double *> _v;
};

#endif
