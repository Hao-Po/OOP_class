#ifndef STUDNET_H
#define STUDENT_H
using namespace std;
#include <string>
#include <map>
#include <algorithm>

class Student{
public:
  Student(string const & stu_id, string const & stu_name)
    : _stu_id(stu_id), _stu_name(stu_name){}

  string id(){
    return _stu_id;
  }

  string name(){
    return _stu_name;
  }

  void setScore(string courseName, int score){
    _courseScores[courseName] = score;
  }

  int getScore(string courseName){
    return _courseScores.find(courseName)->second;
  }

  virtual bool failed(string courseName) = 0;

protected:
  string _stu_id;
  string _stu_name;
  map<string, int> _courseScores;
};

class Undergrad: public Student{
public:
  Undergrad(string const & stu_id, string const & stu_name)
    : Student(stu_id, stu_name){}

  bool failed(string courseName){
    return getScore(courseName) < 60;
  }
};

class Grad : public Student{
public:
  Grad(string const & stu_id, string const & stu_name)
    : Student(stu_id, stu_name){}

  bool failed(string courseName){
    return getScore(courseName) < 70;
  }
};


class Course{
public:
  Course(string const & course_id, string const & course_name)
    : _course_id(course_id), _course_name(course_name){}

  string id(){
    return _course_id;
  }

  string name(){
    return _course_name;
  }

  void add(Student *s){
    _student.push_back(s);
    s->setScore(this->name(),-1);
  }

  void add(Student **first, Student **end){
    for(Student **temp=first;temp<end;temp++){
      add(*temp);
    }
  }

  double size(){
    return _student.size();
  }

  void setScores(vector<string> ids, vector<int> scores){
    for(int i=0;i<ids.size();i++){
      for(auto it=_student.begin();it<_student.end();it++){
        if((*it)->id() == ids[i]){
          (*it)->setScore(this->name(), scores[i]);
        }
      }
    }
  }

  vector<Student *> getStudentsByNameInc(){
    vector<Student *> temp;
    sort(_student.begin(), _student.end(),
      [&](Student *s1, Student *s2){return s1->name() < s2->name();}
    );
    for(int i=0;i<_student.size();i++){
      temp.push_back(_student[i]);
    }

    return temp;
  }

  vector<Student *> failedStudents(){
    vector<Student *> temp;
    for(int i=0;i<_student.size();i++){
      if(_student[i]->failed(this->name())){
        temp.push_back(_student[i]);
      }
    }

    return temp;
  }
private:
  string _course_id;
  string _course_name;
  vector<Student *> _student;
};

#endif
