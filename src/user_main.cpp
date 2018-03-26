#include "dot.h"
#include "vector_io.h"
#include <iostream>

int main(int argc, char ** argv) {
  bool toContinue = true;
  while (toContinue) {
    double *u, *v;
    int dim_u, dim_v;

    try {
      u = promptVectorFromUser(dim_u);
      v = promptVectorFromUser(dim_v);
      double ip = dotProduct(u, dim_u, v, dim_v);
      std::cout << "Inner Product is " << ip << std::endl;
    }
    catch (std::string errorMessage) {
      std::cout << "Error: " << errorMessage << std::endl;
    }

    // toContinue = promptContinueFromUser();
  }
}
