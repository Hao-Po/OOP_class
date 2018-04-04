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

double dotProduct(Vector &u,Vector &v){
  if(u.dim() != v.dim()){
    throw std::string ("Dimension error!");
  }
  double answer=0;
  for(int i=1;i<=u.dim();i++){
    answer += u.at(i)*v.at(i);
  }
  return answer;
}

double angle(Vector &u, Vector &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  double ang=acos(dotProduct(u,v)/u.length(u)/v.length(v));
  return ang;
}

double area(Vector &u, Vector &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  double are=0.5*u.length(u)*v.length(v)*sqrt(1-pow((dotProduct(u,v)/u.length(u)/v.length(v)),2));
  return are;
}

Vector *add(Vector &u, Vector &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  double *temp = new double [u.dim()];
  for(int i=1 ; i<=u.dim() ; i++){
    temp[i-1] = u.at(i)+v.at(i);
  }
  Vector *sum = new Vector(temp,u.dim());
  delete [] temp;
  return sum;
}

#endif
