#ifndef STUDNET_H
#define STUDENT_H
#include <string>
class Student{
public:
  virtual std::string name() const = 0;
  virtual std::string id() const = 0;
  // virtual double getScore() const = 0;
  virtual ~Student(){}
};

#endif
