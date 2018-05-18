#ifndef DOT_H
#define DOT_H
#include <string>
#include "./vector.h"
#include <math.h>

Vector centroid(Vector vertices[], int size){
  double x=0,y=0;
  for(int i=0;i<size;i++){
    x += vertices[i].at(1);
    y += vertices[i].at(2);
  }
  double temp[] = {x/size,y/size};
  return Vector (temp,2);
}

#endif
