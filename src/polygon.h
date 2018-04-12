#ifndef POLYGON_H
#define POLYGON_H
#include "./vector.h"
class Polygon{
public:
  Polygon(Vector vertices [], int numberOfVertices){
    _nerberOfVertices = numberOfVertices;
    _vertices = new Vector [_numberOfVertices];
    for(int i=0;i<_numberOfVertices;i++){
      _vertices[i] = vertices[i];
    }
  }
  Vector vertex(int index){
    return _vertices[index-1];
  }
private:
  Vector * _vertices;
  int _numberOfVertices;
};
#endif
