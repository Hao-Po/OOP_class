#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
class Vector{
public:
  Vector(double *a, int dim){
    _dim = dim;
    _comp = new double [_dim];
    for(int i=0;i<_dim;++i){
      _comp[i] = a[i];
    }
  }

  Vector(Vector &v){
    _dim = v._dim;
    _comp = new double [_dim];
    for(int i=0;i<_dim;i++){
      _comp[i] = v._comp[i];
    }
  }//deep copy constructor

  ~Vector(){
    delete [] _comp;
  }//destructor

  int dim(){
    return _dim;
  }

  double at(int index){
    return _comp[index-1];
  }

  double length(Vector &u){
    double len=0;
    for(int i=1;i<=u.dim();i++){
      len += u.at(i)*u.at(i);
    }
    return sqrt(len);
  }

  double *_comp;
  int _dim;
};
#endif
