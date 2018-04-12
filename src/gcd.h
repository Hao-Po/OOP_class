#ifndef GCD_H
#define GCD_H
int gcd(int m ,int n){
  int r;
  if(m<0 || n<0){
    return 1;
  }
  while(m != 0 && n!=0 ){
    r = m%n;
    m = n;
    n = r;
  }
  return m;
}
#endif
