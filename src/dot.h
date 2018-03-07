double dotProduct(double a[], int dim_a, double b[], int dim_b) {
  assert(dim_a == dim_b);
  double answer = 0;
  for (int i=0; i<dim_a; i++) {
    answer += a[i]*b[i];
  }
  return answer;
}
