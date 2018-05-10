#ifndef TEMPLATE_H
#define TEMPLATE_H

template<class Type>
void change(Type &a, Type &b){
  Type temp;
  temp = a;
  a = b;
  b = temp;
}

template<class Type>
void fill(Type * const array, int size, Type element){
  for(int i=0;i<size;i++){
    array[i] = element;
  }
}

template<class Type>
void reverse(Type * const array, int size){
  for(int i=0;i<(size/2);i++){
    change(array[i],array[size-i-1]);
  }
}

template<class Type>
Type * deepCopy(Type * const array, int size){
  Type * _array = new Type [size];
  for(int i=0;i<size;i++){
    _array[i] = array[i];
  }
  return _array;
}

#endif
