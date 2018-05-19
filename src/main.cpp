#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "./vector_io.h"
#include "./vector.h"
#include "./polygon.h"
using namespace std;

int main(int argc,char* argv[]){
  for(int i=1;argv[i]!=0;i++){
    fstream file(argv[i]);
    int numberOfVertices;
    file >> numberOfVertices;
    string s[numberOfVertices+1];
    Vector v[numberOfVertices];
    for(int i=0;i<numberOfVertices+1;i++){
      string temp_s;
      getline(file,temp_s);
      s[i] = temp_s;
    }
    for(int i=0;i<numberOfVertices;i++){
      v[i] = *makeVectorFromString(s[i+1]);
    }
    Polygon p = createPolygon(v,numberOfVertices);
    cout << "Length of polygon is: " << fixed << setprecision(2) << p.length() << endl
         << "Area of polygon is: " << p.area() << endl;

    file.close();
  }
}
