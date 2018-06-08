#ifndef POLYGON_H
#define POLYGON_H
#include "./dot.h"
#include "./vector.h"
#include "./bubblesort.h"
#include "./shape.h"
class Polygon: public Shape{
public:
  // Polygon(Vector vertices [], int numberOfVertices) :
  //   _numberOfVertices(numberOfVertices),
  //   _vertices(new Vector[numberOfVertices]){
  //   for(int i=0;i<_numberOfVertices;i++){
  //     _vertices[i] = vertices[i];
  //   }
  // }

  Polygon() : _numberOfVertices(-1),_vertices(nullptr){}

  Polygon(Polygon const &p) :
    _numberOfVertices(p._numberOfVertices),
    _vertices(new Vector[p._numberOfVertices]){
    for(int i=0;i<_numberOfVertices;i++){
      _vertices[i] = p._vertices[i];
    }
  }//depp copy constructor

  ~Polygon(){
    delete [] _vertices;
  }//destructor

  Vector vertex(int index) const{
    return _vertices[index-1];
  }

  Polygon & operator=(Polygon const &p){
    if(_vertices){
      delete [] _vertices;
    }
    _numberOfVertices = p._numberOfVertices;
    _vertices = new Vector [p._numberOfVertices];
    for(int i=0;i<p._numberOfVertices;i++){
      _vertices[i] = p._vertices[i];
    }
    return *this;
  }

  double area() const{
    double arc=0;
    for(int i=0;i<_numberOfVertices-2;i++){
      arc += triangleArea(_vertices[0],_vertices[i+1],_vertices[i+2]);
    }
    return arc;
  }

  double length() const{
    double len=0;
    for(int i=1;i<_numberOfVertices;i++){
      len += (vertex(i+1)-vertex(i)).length();
    }
    len += (vertex(1)-vertex(_numberOfVertices)).length();
    return len;
  }

private:
  Vector * _vertices;
  int _numberOfVertices;
};

Polygon createPolygon(Vector vertices[],int size){
  Vector O = centroid(vertices,size);
  Vector R = vertices[0] - O;
  bubbleSort(vertices,vertices+size,
    [&](Vector u,Vector v){return angle(R,u-O)>angle(R,v-O);}
  );
  return Polygon (vertices,size);
}
#endif
