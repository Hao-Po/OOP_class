#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>

class Vector{
public:
  Vector(double * a, int dim){
    _dim = dim;
    _comp = new double [_dim];
    for(int i=0;i<_dim;++i){
      _comp[i] = a[i];
    }
  }

  Vector(){
    _comp = nullptr;
    _dim = -1;
  }

  Vector(Vector const &v){
    _dim = v._dim;
    _comp = new double [_dim];
    for(int i=0;i<_dim;i++){
      _comp[i] = v._comp[i];
    }
  }//deep copy constructor

  ~Vector(){
    delete [] _comp;
  }//destructor

  int dim() const {
    return _dim;
  }

  double at(int index) const {
    return _comp[index-1];
  }

  double length() const{
    double len=0;
    for(int i=1;i<=_dim;i++){
      len += _comp[i-1]*_comp[i-1];
    }
    return sqrt(len);
  }

  Vector & operator=(Vector &u){
    if(_comp){
      delete [] _comp;
    }
    _comp = new double [u._dim];
    _dim = u._dim;
    for(int i=0;i<u._dim;++i){
      _comp[i] = u._comp[i];
    }

    return *this;
  }

  double *_comp;
  int _dim;
};

double dotProduct(Vector const &u,Vector const &v){
  if(u.dim() != v.dim()){
    throw std::string ("Dimension error!");
  }
  double answer=0;
  for(int i=1;i<=u.dim();i++){
    answer += u.at(i)*v.at(i);
  }
  return answer;
}

bool pointingOut(Vector const & u, Vector const & v){
  return u.at(1)*v.at(2)-u.at(2)*v.at(1)>=0;
}

double angle(Vector const  &u, Vector const &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  if(pointingOut(u,v)){
    return acos(dotProduct(u,v)/u.length()/v.length());
  }
  else{
    return 2*M_PI-acos(dotProduct(u,v)/u.length()/v.length());
  }
}

double area(Vector &u, Vector &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  double are=0.5*u.length()*v.length()*sqrt(1-pow((dotProduct(u,v)/u.length()/v.length()),2));
  return are;
}

Vector *add(Vector &u, Vector &v){
  if (u.dim() != v.dim() || u.dim()==0){
    throw "Dimension error";
  }
  double *temp = new double [u.dim()];
  for(int i=1;i<=u.dim();i++){
    temp[i-1] = u.at(i)+v.at(i);
  }
  Vector *sum = new Vector(temp,u.dim());
  delete [] temp;
  return sum;
}

Vector operator-(Vector const &u, Vector const &v){
  double temp[u.dim()];
  for(int i=0;i<u.dim();i++){
    temp[i] = u.at(i+1)-v.at(i+1);
  }

  return Vector (temp,u.dim());
}

double triangleArea(Vector &a ,Vector &b ,Vector &c){
  double lengA = (b-a).length();
  double lengB = (c-b).length();
  double lengC = (a-c).length();
  double S = (lengA+lengB+lengC)/2;
  double arc = sqrt(S*(S-lengA)*(S-lengB)*(S-lengC));
  return arc;
}

#endif
