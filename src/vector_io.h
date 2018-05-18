#ifndef VECTORIO_H
#define VECTORIO_H
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include "./vector.h"
using namespace std;

Vector * pullVectorFromString(std::string s) {
  if(s[s.length()-1] != ']'){
    string error("Invalid input!");
    throw error;
  }
  std::stringstream ss(s);
  int dim;
  ss >> dim;
  if(dim<=0){
    string error("Dimension need a positive number!");
    throw error;
  }
  char ch;
  ss >> ch;
  if(ch == '.'){
    string error("Dimension need a integer!");
    throw error;
  }
  if(ch != '['){
    string error("Invalid input!");
    throw error;
  }
  double *v = new double [dim];
  for(int i=0 ; i<dim ; i++){
    ss >> v[i] >> ch;
    if(ch != ',' && ch != ']' ){
      string error("Invalid input!");
      throw error;
    }
    if (ch ==']' && i<dim-1){
      string error("Dimension error low!");
      throw error;
    }

  }
  Vector *vec = new Vector(v,dim);
  if(ch != ']'){
    string error("Dimension error!");
    throw error;
  }
  delete [] v;
  return vec;
}

Vector * promptVectorFromUser(){
    std::string line;
    std::cout << "Input a vector in the following format \"n [c1,...,cn]\": ";
    std::getline(std::cin, line);
    std::cout << "Your input:" << line << std::endl;

    return pullVectorFromString(line);
  }

  Vector * makeVectorFromString(std::string s){
    std::stringstream ss(s);
    char ch;
    ss >> ch;
    double *v = new double [2];
    for(int i=0 ; i<2 ; i++){
      ss >> v[i] >> ch;
    }
    Vector *vec = new Vector(v,2);
    delete [] v;
    return vec;
  }

#endif
