#include "dot.h"
#include "vector_io.h"
#include <iostream>

int main(int argc, char ** argv) {
  bool toContinue = true;
  while (toContinue) {
    Vector *u,*v;

    try {
      u = promptVectorFromUser();
      v = promptVectorFromUser();
      double ip = dotProduct(*u,*v);
      std::cout << "Inner Product is " << ip << std::endl;
    }
    catch (std::string errorMessage) {
      std::cout << "Error: " << errorMessage << std::endl;
    }

    // toContinue = promptContinueFromUser();
  }
}
