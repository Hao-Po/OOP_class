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
      if(matrix[i][j] == -0){matrix[i][j] = abs(matrix[i][j]);}
      cout << left << setw(9) << matrix[i][j] << left;
      if(j == n-1){cout << endl;}
    }
  }
}

double * EigenValue(double **matrix){
  double a = 1;
  double b = -(matrix[0][0]+matrix[1][1]);
  double c = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
  double lamda1 = (-b+sqrt(b*b-4*a*c))/(2*a);
  double lamda2 = (-b-sqrt(b*b-4*a*c))/(2*a);
  cout << "EigenValue: " << lamda1 << " or " << lamda2 << endl;
  double * value = new double [2];
  value[0] = lamda1; value[1] = lamda2;
  return value;
}

void RREF(double **matrix, int m, int n){
  for(int zero=0;zero<n-1;zero++){
    int x,y,row=zero,col=zero;
    while(matrix[row][col] == 0){
      x=row+1;
      if(x > m-1){col++;row = zero;}
      row++;
    }//find the row which the first number is not 0
    int pivoty = col;

    row=col=zero;
    while(matrix[row][col] == 0){
      if(x > m-1){break;}
        for(int i=0;i<n;i++){
          double temp = matrix[row][i];
          matrix[row][i] = matrix[x][i];
          matrix[x][i] = temp;
        }
    }//interchange

    for(int i=row+1;i<m;i++){
      double mul = -(matrix[i][pivoty] / matrix[row][col]);
      for(int j=0;j<n;j++){
        if(mul == 0){continue;}
        matrix[i][j] += mul*matrix[row][j];
      }
    }//downward
  }

  for(int i=m-1,j;i>0;i--){
      for(j=0;matrix[i][j]==0;j++){}
      for(int x=0;x<i;x++){
      if(matrix[i][j] == 0){break;}
      double mul = -(matrix[x][j] / matrix[i][j]);
      for(int y=0;y<n;y++){
        if(mul == 0){continue;}
        matrix[x][y] += mul*matrix[i][y];
      }
    }
  }//upward

  for(int i=0,j;i<m;i++){
    for(j=0;matrix[i][j]==0;j++){}
    for(int y=n-1;y>=0;y--){
      if(matrix[i][j]==0){break;}
      matrix[i][y] /= matrix[i][j];
    }
  }/*scaling*/

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
