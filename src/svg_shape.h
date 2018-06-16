#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H
class SvgShape{
public:
  SvgShape(){

  }

  void setFillColor(std::string _fillColor){

  }

  void setStroke(double _strokeWidth, std::string _strokeColor){

  }

  virtual std::string toSVG() const = 0;
};
void setSvgShapeStyle(SvgShape *shape, double _strokeWidth, std::string _strokeColor, std::string _fillColor){

}

std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const & shape){

}
#endif
