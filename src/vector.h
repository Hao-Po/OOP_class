#ifndef VECTOR_H
#define VECTOR_H
// #include <assert.h>
#include <string>

typedef std::pair<double,double> Point;

double innerProduct (Point a, Point b) {
  return a.first * b.first + a.second * b.second;
}

double innerProduct (double a[], double b[], int dim_a, int dim_b) {
  // assert(dim_a>0 && dim_b>0 && dim_a==dim_b); // forced exit if failed
  if (dim_a<=0 || dim_b<=0 || dim_a!=dim_b)
    throw std::string("illegal dimension");

  double ip = 0;
  for (int i=0; i<dim_a; ++i)
    ip += a[i] * b[i];
  return ip;
}


class Vector {
public:
  Vector (double a[], int dim): _dim(dim), _v(new double[dim]) {
    for (int i=0; i< _dim; ++i)
      _v[i] = a[i];
  }

  double at(int i) const {
    return _v[i-1];
  }

  int dim() const {
    return _dim;
  }

private:
  double * _v;
  int _dim;
};

double innerProduct(Vector const & u, Vector const & v) {
  if (u.dim() != v.dim())
    throw std::string("illegal dimension");

    double ip = 0;
    for (int i=1; i<=u.dim(); ++i)
      ip += u.at(i) * v.at(i);
    return ip;
}

#endif
