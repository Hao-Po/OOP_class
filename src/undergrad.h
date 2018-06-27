#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "./student.h"
#include "./course.h"
#include <string>
class Undergrad: public Student{
public:
  Undergrad(std::string id, std::string name)
    : _id(id), _name(name){}

  std::string name() const {
    return _name;
  }

  std::string id() const {
    return _id;
  }

  // double getScore(std::string s){
  //
  // }

private:
  std::string _id;
  std::string _name;
};

class Grad : public Student{
public:
  Grad(std::string id, std::string name)
    : _id(id), _name(name){}

  std::string name() const {
    return _name;
  }

  std::string id() const {
    return _id;
  }

private:
  std::string _id;
  std::string _name;
};
#endif
