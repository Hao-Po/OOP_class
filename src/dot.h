#ifndef DOT_H
#define DOT_H
#include <string>
#include "./vector.h"
#include <math.h>

// double dotProduct(double a[], int dim_a, double b[], int dim_b) {
//   if (dim_a != dim_b){
//     std::string error("undifined");
//     throw error;
//   }
//   double answer = 0;
//   for (int i=0; i<dim_a; i++) {
//     answer += a[i]*b[i];
//   }
//   return answer;
// }

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
