#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H
class SvgShape{
public:
  SvgShape(){
    _strokeWidth = 0;
    _strokeColor = "black";
    _fillColor = "black";
  }

  void setFillColor(std::string fillColor){
    _fillColor = fillColor;
  }

  void setStroke(double strokeWidth, std::string strokeColor){
    _strokeWidth = strokeWidth;
    _strokeColor = strokeColor;
  }

  virtual std::string toSVG() const = 0;

std::string _fillColor;
std::string _strokeColor;
double _strokeWidth;
};

void setSvgShapeStyle(SvgShape *shape, double strokeWidth, std::string strokeColor, std::string fillColor){
    shape->setFillColor(fillColor);
    shape->setStroke(strokeWidth, strokeColor);
}

std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const & shape){
  std::string s = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" +
  std::to_string(width)  + "\" height=\"" + std::to_string(height) + "\" viewBox=\"0 0 100 100\">";
  for(int i=0;i!=shape.size();i++){
    s += shape[i]->toSVG();
  }
  s += "</svg>";
  return s;
}
#endif
