#include <gtest/gtest.h>
#include "./function.h"
using namespace std;

int main( int argc , char **argv )
{
    int m,n;
    cout << "Enter the size of matrix (row col):" ;
    cin >> m >> n;
    double **matrix = new double *[m];
    for(int i=0;i<m;i++){
      matrix[i] = new double [n];
    }
    ReadMatrix(matrix,m,n);
    double * value = EigenValue(matrix);
    RREF(matrix,m,n);



    PrintMatrix(matrix,m,n);
}
