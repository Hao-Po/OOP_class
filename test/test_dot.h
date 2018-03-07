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
