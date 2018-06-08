#ifndef FUNCTION_H
#define FUNCTION_H
#include <cmath>
using namespace std;
void ReadMatrix(double **matrix, int m, int n){
  for(int i=0;i<m;i++){
    cout << "Enter Row " << i+1 << "(x1 x2... xn):";
    for(int j=0;j<n;j++){
      cin >> matrix[i][j];
    }
  }
}

void PrintMatrix(double **matrix, int m, int n){
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(matrix[i][j]==-0){matrix[i][j]=abs(matrix[i][j]);}
      cout << left << setw(9) << matrix[i][j] << left;
      if(j==n-1){cout << endl;}
    }
  }
}

double * EigenValue(double **matrix){
  double a = 1;
  double b = -(matrix[0][0]+matrix[1][1]);
  double c = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
  double lamda1 = (-b+sqrt(b*b-4*a*c))/2*a;
  double lamda2 = (-b-sqrt(b*b-4*a*c))/2*a;
  cout << "EigenValue: " << lamda1 << " or " << lamda2 << endl;
  double * value = new double [2];
  value[0] = lamda1; value[1] = lamda2;
  return value;
}

void RREF(double **matrix, int m, int n){
  int x,y,row=col=0;
  while(matrix[row][col] == 0){

    
  }
}



int gcd(int m ,int n){
  if(m<0 || n<0){
    return 1;
  }
  while(m != 0 && n!=0 ){
    int r = m%n;
    m = n;
    n = r;
  }
  return m;
}


#endif
