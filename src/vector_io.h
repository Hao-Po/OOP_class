#ifndef VECTORIO_H
#define VECTORIO_H

#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

double * pullVectorFromString(std::string s, int * dim) {
  if(s[s.length()-1] != ']'){
    string error("Invalid input!");
    throw error;
  }
  std::stringstream ss(s);
  ss >> *dim;
  if((*dim)<=0){
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
  double *v = new double [*dim];
  for(int i=0 ; i<*dim ; i++){
    ss >> v[i] >> ch;
    if(ch != ',' && ch != ']' ){
      string error("Invalid input!");
      throw error;
    }
    if (ch ==']' && i<*dim-1){
      string error("Dimension error low!");
      throw error;
    }

  }
  if(ch != ']'){
    string error("Dimension error!");
    throw error;
  }
  return v;
}

double * promptVectorFromUser(int &dim){
    std::string line;
    std::cout << "Input a vector in the following format \"n [c1,...,cn]\": ";
    std::getline(std::cin, line);
    std::cout << "Your input:" << line << std::endl;
    double * vec = pullVectorFromString(line, &dim);

    return vec;
}

#endif
