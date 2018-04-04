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

#endif
