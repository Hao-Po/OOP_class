#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "./term.h"
#include <algorithm>
class Polynomial {
public:
  Polynomial(Term * const ts ,int ts_size ,int degree){
    _degree = degree;
    _ts_size = ts_size;
    _ts = new Term [_ts_size];
    for(int i=0;i<_ts_size;i++){
      _ts[i] = ts[i];
    }
  }

  Polynomial(const Polynomial &p){
    _degree = p._degree;
    _ts_size = p._ts_size;
    _ts = new Term [_ts_size];
    for(int i=0;i<_ts_size;i++){
      _ts[i] = p._ts[i];
    }
  }

  Polynomial(){
    _degree = 0;
    _ts_size = 0;
    _ts = nullptr;
  }

  ~Polynomial(){
    delete [] _ts;
  }

  Polynomial operator =(const Polynomial &p){
    if(_ts){
      delete [] _ts;
    }
    _degree = p._degree;
    _ts_size = p._ts_size;
    _ts = new Term [p._ts_size];
    for(int i=0;i<p._ts_size;i++){
      _ts[i] = p._ts[i];
    }
    return *this;
  }

  Term term(int degree) const{
    for(int i=0;i<_ts_size;i++){
      if(_ts[i].exponent() == degree){
        return _ts[i];
      }
    }
    return Term (0,degree);
  }

  int degreeOfPolynomial() const{
    return _degree;
  }

  void multiplyByTerm(Term t){
    if(t.coefficient() == 0){
      for(int i=0;i<_ts_size;i++){
        _ts[i] = _ts[i]*t;
      }
      _degree = 0;
    }
    else{
      for(int i=0;i<_ts_size;i++){
        _ts[i] = _ts[i]*t;
      }
      _degree = _degree+t.exponent();
    }
  }
private:
  int _degree;
  int _ts_size;
  Term * _ts;
};
Polynomial operator +(const Polynomial &p ,const Polynomial &q){
    int degree = std::max(p.degreeOfPolynomial(),q.degreeOfPolynomial());
    Term ts[degree+1];
    for(int i=0;i<=degree;i++){
       Term tempP = p.term(i);
       Term tempQ = q.term(i);
       double coef = tempP.coefficient() + tempQ.coefficient();
       Term tempPlus(coef,i);
       ts[i] = tempPlus;
    }
    return Polynomial (ts,degree+1,degree);
}
#endif
