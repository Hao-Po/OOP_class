#ifndef SHAPE_H
#define SHAPE_H
class Shape{
public:
  virtual double area() const = 0;//pure virtual
  virtual double length() const = 0;
  virtual ~Shape(){}
};
#endif
