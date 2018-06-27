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
    int n = b-a;
    std::sort(a,b,
      [&](Student *a,Student *b){return a->name()<b->name();}
    );
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

  // void setScores(std::string *ids, int *scores){
  //   for(int i=0;i<ids->size();i++){
  //     for(int j=0;j<_student.size();j++){
  //       if(ids[i] == _student[j]->id()){
  //         _student[j]->Student::setScore(scores[i]);
  //       }
  //     }
  //   }
  // }


private:
  std::string _id;
  std::string _name;
  std::vector<Student*> _student;
  std::map<std::string, int> _cn;
};
#endif
