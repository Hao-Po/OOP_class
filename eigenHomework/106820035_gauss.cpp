#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int m,n,i,j,k,zero=0;

int main(){
    cout << "Enter the size of matrix (row col):" ;
    cin >> m ; cin >> n ;
    double matrix[m][n];
    for(i=0;i<m;i++){
      cout << "Enter Row " << i+1 << "(x1 x2... xn):";
      for(j=0;j<n;j++){
        cin >> matrix[i][j];
      }
    }/*read matrix*/

    for(zero=0;zero<n-1;zero++){
      int x,y,row=zero,col=zero;
      double temp;
      while(matrix[row][col]==0){
        x=row+1;
        row++;
        if(x>m-1){
          col++;row=zero;
        }
      }/*尋找頭非0的列*/

      int pivoty=col;
      row=col=zero;
      while(matrix[row][col]==0){
        if(x>m-1){break;}
          for(i=0;i<n;i++){
            temp=matrix[row][i];
            matrix[row][i]=matrix[x][i];
            matrix[x][i]=temp;
          }
      }/*interchange*/

      double mul;
      for(i=row+1;i<m;i++){
        mul=-(matrix[i][pivoty]/matrix[row][col]);
        for(j=0;j<n;j++){
          if(mul==0){continue;}
          matrix[i][j]=matrix[i][j]+mul*matrix[row][j];
        }
      }/*replacement*/
    }/*echelon form*/

    zero=0;
    int x,y,row=zero,col=zero;
    for(i=m-1;i>0;i--){
      for(j=col;matrix[i][j]==0 && j<n-2;j++){}
      double mul;
      for(x=0;x<i;x++){
        if(matrix[i][j]==0){break;}
        mul=-(matrix[x][j]/matrix[i][j]);
        for(y=0;y<n;y++){
          if(mul==0){continue;}
          matrix[x][y]=matrix[x][y]+mul*matrix[i][y];
        }
      }
    }/*replacement2*/

    row=col=zero;
    for(i=0;i<m;i++){
      for(j=col;matrix[i][j]==0 && j<n-2;j++){}
      for(y=n-1;y>-1;y--){
        if(matrix[i][j]==0){break;}
        matrix[i][y]/=matrix[i][j];
      }
    }/*scaling*/

    cout << endl << "Become Reduce Echelon Form:" << endl;
    for(i=0;i<m;i++){
      for(j=0;j<n;j++){
        if(matrix[i][j]==-0){matrix[i][j]=abs(matrix[i][j]);}
        cout << left << setw(9) << matrix[i][j] << left;
        if(j==n-1){cout << endl;}
      }
    }/*print reduce echelon form*/

    bool front=0,back=0;
    for(i=m-1,j=0;j<n-1;j++){
      if(matrix[i][j]!=0){front=1;}
      if(matrix[m-1][n-1]!=0){back=1;}
    }
    if(front==0 && back==0){cout << endl << "Infinite solution" << endl; system("pause"); return 0;}
    if(front==0 && back==1){cout << endl << "No solution" << endl; }
    else{
      int count;
      for(i=0;i<m;i++){
        count=0;
        for(j=0;j<n-1;j++){
          if(matrix[i][j]!=0){count++;}
        }
        if(count>1){cout << endl << "Infinite solution" << endl; system("pause"); return 0;}
      }
      cout << endl ;
      for(i=0;i<m;i++){
        cout << 'x' << i+1 << '=' << matrix[i][n-1] << endl;
      }
    }/*print solution*/

    system("pause"); 
    return 0;
}
