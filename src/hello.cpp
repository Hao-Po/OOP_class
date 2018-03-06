#include <stdio.h>
#include <assert.h>

double dotProduct(double a[], int dim_a, double b[], int dim_b) {
  assert(dim_a == dim_b);
  double answer = 0;
  for (int i=0; i<dim_a; i++) {
    answer += a[i]*b[i];
  }
  return answer;
}

void testDotProduct() {
  double u[] = {1,1};
  double v[] = {0,1};
  double dp = dotProduct(u, 2, v, 2);
  assert(1==dp);
}

void testDotProduct_2() {
  double u[] = {1,1,0};
  double v[] = {0,1,1};
  double dp = dotProduct(u, 3, v, 3);
  assert(1==dp);
}

void testDotProduct_3() {
  double u[] = {1,0};
  double v[] = {1,1,1};
  double dp = dotProduct(u, 2, v, 3);
}


int main(int argc, char **argv) {
  printf("Hello, dot product!\n");

  testDotProduct();
  testDotProduct_2();
  testDotProduct_3();
}
