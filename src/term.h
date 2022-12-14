#ifndef TERM_H
#define TERM_H
class Term {
public:
  Term(){
    _coefficient = 0;
    _exponent = 0;
  }

  Term(double coef ,int exp){
    _coefficient = coef;
    _exponent = exp;
  }

  double coefficient() const{
    return _coefficient;
  }

  int exponent() const{
    return _exponent;
  }

  bool operator ==(Term const &t) const{
      return this->_coefficient == t._coefficient && this->_exponent == t._exponent;
  }

  Term operator *(Term const &t) const{
    double temp_coef;
    int temp_exp;
    if(this->_coefficient == 0 || t.coefficient() == 0){
      temp_coef = 0;
      temp_exp = 0;
    }
    else{
      temp_coef = this->_coefficient*t._coefficient;
      temp_exp = this->_exponent+t._exponent;
    }
    return Term (temp_coef,temp_exp);
  }

  bool isZero() const{
      return _coefficient == 0;
  }
private:
  double _coefficient;
  int _exponent;
};
#endif
