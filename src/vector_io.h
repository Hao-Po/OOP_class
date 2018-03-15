#ifndef VECTORIO_H
#define VECTORIO_H
#include <sstream>
double* pullvectorfromstring(std:: string s, int* dim){
  std:: stringstream ss(s);
  ss >> *dim;
  char ch;
  ss >> ch;
  double * v = new double(*dim);
  for(int i=0;i<*dim;i++){
    ss >> v[i] >> ch ;
  }
  return v;
}

#endif
