#include <stdio.h>
#include <assert.h>

int add(int a, int b) {
  return a+b;
}

int main(int argc, char **argv) {
  printf("Hello, C!\n");
  int result = add(2,3);
  assert(5==result);
}
