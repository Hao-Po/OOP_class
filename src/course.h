#ifndef COURSE_H
#define COURSE_H
#include "undergrad.h"
#include <algorithm>
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

  template<typename Autotype>
  void add(Autotype *a, Autotype *b){
    for(auto it=a;it!=b;it++){
      _student.push_back(*it);
    }
  }

  double size(){
    return _student.size();
  }

  std::vector<Student *> getStudentsByNameInc(){
    return _student;
  }


private:
  std::string _id;
  std::string _name;
  std::vector<Student*> _student;
  std::map<std::string, int> _cn;
};
#endif
