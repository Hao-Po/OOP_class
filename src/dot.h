double dotProduct(double a[], int dim_a, double b[], int dim_b) {
  if (dim_a != dim_b)
    throw "undefined";
  double answer = 0;
  for (int i=0; i<dim_a; i++) {
    answer += a[i]*b[i];
  }
  return answer;
}

double length(double v[],int dim){
  double len=0;
  for(int i=0;i<dim;i++){
    len += v[i]*v[i];
  }
  return sqrt(len);
}

double angle(double a[],int dim_a,double b[],int dim_b){
  if (dim_a != dim_b || dim_a==0){
    throw "undefined";
  }
  double ang=acos(dotProduct(a,dim_a,b,dim_b)/length(a,dim_a)/length(b,dim_b));
  return ang;
}

double area(double a[],int dim_a,double b[],int dim_b){
  if (dim_a != dim_b || dim_a==0){
    throw "undefined";
  }
  double are=0.5*length(a,dim_a)*length(b,dim_b)*sqrt(1-pow((dotProduct(a,dim_a,b,dim_b)/length(a,dim_a)/length(b,dim_b)),2));
  return are;
}
