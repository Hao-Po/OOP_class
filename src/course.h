#ifndef COURSE_H
#define COURSE_H
#include "undergrad.h"
#include <vector>
#include <map>
class Course{
public:
  Course(std::string id, std::string name): _id(id), _name(name){

  }

  std::string name() const {
    return _name;
  }

  std::string id() const {
    return _id;
  }

  void add(Student *s){
    _student.push_back(s);
  }

  double size(){
    return _student.size();
  }

  void setScore(std::string *courseName, int *score){
    auto it2=score->begin();
    for(auto it=courseName->begin();it!=courseName->end();it++,it2++){
      _cn[it] = it2;
    }
  }

private:
  std::string _id;
  std::string _name;
  std::vector<Student*> _student;
  std::map<std::string, Student *> _cn;
};
#endif
