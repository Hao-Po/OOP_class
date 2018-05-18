#include <iostream>
#include <fstream>
#include <string>
#include "./vector_io.h"
#include "./vector.h"
#include "./polygon.h"
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
    Polygon p = createPolygon(v,numberOfVertices);
    cout << "Length of polygon is:" << p.length() << endl
         << "Area of polygon is:" << p.area() << endl;

    file.close();
  }
}
