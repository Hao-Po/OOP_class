#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template<typename Autotype>
void change(Autotype &a, Autotype &b){
  Autotype temp;
  temp = a;
  a = b;
  b = temp;
}

template<typename Autotype>
bool LessThan(Autotype a, Autotype b){
  return a<b;
}

template<typename Autotype>
bool GreaterThan(Autotype a, Autotype b){
  return a>b;
}

template<typename Autotype,typename Functiontype>
void bubbleSort(Autotype *a, Autotype *b,Functiontype comp){
  int n = b-a;
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++){
      if(comp(a[j],a[j+1])){
        change(a[j],a[j+1]);
      }
    }
  }
}
#endif
