#include <iostream>
#include <fstream>
#include <string>
#include "../src/vector_io.h"
#include "../src/vector.h"
#include "../src/dot.h"
#include "../src/polygon.h"
#include "../src/bubblesort.h"
using namespace std;

int main(int argc,char* argv[]){
  fstream file;
  for(int i=1;argv[i]!=0;i++){
    file.open(argv[i],ios::in);
    int numberOfVertices;
    string s[50];
    Vector v[50];
    file >> numberOfVertices;
    for(int i=0;i<numberOfVertices;i++){
      file >> s[i];
      v[i] = *makeVectorFromString(s[i]);
    }
    Vector O = centroid(v,numberOfVertices);
    Vector R = v[0] - O;
    bubbleSort(v,v+numberOfVertices,
      [&](Vector u,Vector v){return angle(R,u-O)<angle(R,v-O);}
    );
    Polygon p(v,numberOfVertices);
    cout << "Length of polygon is:" << p.length() << endl
         << "Area of polygon is:" << p.area() << endl;

    file.close();
  }
}
