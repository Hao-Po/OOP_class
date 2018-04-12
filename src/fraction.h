#ifndef FRACTION_H
#define FRACTION_H
#include <cmath>
#include <sstream>
#include "gcd.h"
class Fraction{
public:
  Fraction(double const &numerator ,double const &denominator){
    _numerator = numerator;
    _denominator = denominator;
    if(_denominator == 0){
      std::string s("denominator can't be 0");
      throw s;
    }
  }

  Fraction(){
    _numerator = 0;
    _denominator = 1;

  }

  Fraction(double const &numerator){
    _numerator = numerator;
    _denominator = 1;
  }

  double numerator(){
    return abs(_numerator);
  }

  double denominator(){
    return abs(_denominator);
  }

  char sign(){
    if((_numerator>=0 && _denominator>=0) || (_numerator<=0 && _denominator<=0)){
      _sign = '+';
    }
    else{
      _sign = '-';
    }
    return _sign;
  }

  std::string str(){
    std::stringstream ss;
    if((_numerator>=0 && _denominator>=0) || (_numerator<=0 && _denominator<=0)){
      if(_denominator == 1 || _denominator == -1){
        ss << abs(_numerator);
      }
      else if(_numerator == 0){
        ss << abs(_numerator);
      }
      else{
        ss << abs(_numerator) << "/" << abs(_denominator);
      }
    }
    else{
      if(_denominator == 1 || _denominator == -1){
        ss << "-" << abs(_numerator);
      }
      else if(_numerator == 0){
        ss << abs(_numerator);
      }
      else{
        ss << "-" << abs(_numerator) << "/" << abs(_denominator);
      }
    }
    std::string number;
    ss >> number;
    return number;
  }
  double _numerator ,_denominator;
  char _sign;
};

Fraction operator+ (Fraction a ,Fraction b){
  double temp_numerator,temp_denominator;
  if(a.sign() == '-' || b.sign() == '-'){
    temp_numerator = a.numerator()*b.denominator() - b.numerator()*a.denominator();
    temp_denominator = a.denominator()*b.denominator();
  }
  else if(a.sign() == '-' && b.sign() == '-'){
    temp_numerator = -(a.numerator()*b.denominator() + b.numerator()*a.denominator());
    temp_denominator = a.denominator()*b.denominator();
  }
  else{
    temp_numerator = a.numerator()*b.denominator() + b.numerator()*a.denominator();
    temp_denominator = a.denominator()*b.denominator();
  }
  double gcd_number = gcd(abs(temp_numerator),temp_denominator);
  temp_numerator /= gcd_number;
  temp_denominator /= gcd_number;
  Fraction c(temp_numerator,temp_denominator);
  return c;
}

bool FractionLT(Fraction a ,Fraction b){
  if(a.sign() == '+' && b.sign() == '-'){
    return 0;
  }
  else if(a.sign() == '-' && b.sign() == '+'){
    return 1;
  }
  else if(a.sign() == '+' && b.sign() == '+'){
    double a_numerator = a.numerator()*b.denominator();
    double b_numerator = b.numerator()*a.denominator();
    if(a_numerator>b_numerator){
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    double a_numerator = a.numerator()*b.denominator();
    double b_numerator = b.numerator()*a.denominator();
    if(a_numerator>b_numerator){
      return 1;
    }
    else{
      return 0;
    }
  }
}

bool FractionGT(Fraction a ,Fraction b){
  if(a.sign() == '+' && b.sign() == '-'){
    return 1;
  }
  else if(a.sign() == '-' && b.sign() == '+'){
    return 0;
  }
  else if(a.sign() == '+' && b.sign() == '+'){
    double a_numerator = a.numerator()*b.denominator();
    double b_numerator = b.numerator()*a.denominator();
    if(a_numerator>b_numerator){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    double a_numerator = a.numerator()*b.denominator();
    double b_numerator = b.numerator()*a.denominator();
    if(a_numerator>b_numerator){
      return 0;
    }
    else{
      return 1;
    }
  }
}
#endif
