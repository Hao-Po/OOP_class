#ifndef UNDERGRAD_H
#define UNDERGRAD_H
#include "./student.h"
#include "./course.h"
#include <string>
class Undergrad: public Student{
public:
  Undergrad(std::string id, std::string name)
    : _id(id), _name(name), _score(-1){}

  std::string name() const {
    return _name;
  }

  std::string id() const {
    return _id;
  }

  int setScore(int number){
    return number;
  }

private:
  std::string _id;
  std::string _name;
  int _score;
};

class Grad : public Student{
public:
  Grad(std::string id, std::string name)
    : _id(id), _name(name), _score(-1){}

  std::string name() const {
    return _name;
  }

  std::string id() const {
    return _id;
  }

  int setScore(int number){
    return _score;
  }
private:
  std::string _id;
  std::string _name;
  int _score;
};
#endif
