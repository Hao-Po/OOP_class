// #include "../src/student.h"
#include "../src/undergrad.h"
#include "../src/course.h"


TEST (StudentTest, Student) {
  // creating students : undergrads and grads
  Student * s001 = new Undergrad("U2018EECS001", "John");
  Student * s002 = new Undergrad("U2018EECS002", "Mary");
  Student * s003 = new Undergrad("U2018EECS003", "Nick");
  Student * g001 = new Grad("G2018CSIE001", "Mike");
  Student * g002 = new Grad("G2018CSIE002", "Jane");

  ASSERT_EQ("U2018EECS001", s001->id());
  ASSERT_EQ("G2018CSIE002", g002->id());
  ASSERT_EQ("John", s001->name());
  ASSERT_EQ("Jane", g002->name());
}

TEST (CourseTest, Course) {
  // creating course oop
  Course * oop = new Course ("EECS201", "Object-oriented Programming");
  ASSERT_EQ("EECS201", oop->id());
  ASSERT_EQ("Object-oriented Programming", oop->name());
}

TEST (CourseTest, addStudent) {
  Student * s001 = new Undergrad("U2018EECS001", "John");
  Course * oop = new Course ("EECS201", "Object-oriented Programming");

  // adding undergrad s001 to course oop
  oop->add(s001);
  ASSERT_EQ(1, oop->size());

  // should have the effect adding a Score of -1 for the course
  // of name "Object-oriented Programming" for the student added
  // hint: use a member function Student::setScore(std::string courseName, int score) to
  // insert a map entry {"Object-oriented Programming", -1}
  // ASSERT_EQ(-1, s001->getScore("Object-oriented Programming"));
}

TEST (CourseTest, addMultiStudents) {
  Student * s002 = new Undergrad("U2018EECS002", "Mary");
  Student * s003 = new Undergrad("U2018EECS003", "Nick");
  Student * g001 = new Grad("G2018CSIE001", "Mike");
  Student * g002 = new Grad("G2018CSIE002", "Jane");
  Course * oop = new Course ("EECS201", "Object-oriented Programming");

  // adding two students
  Student * twoStudents[]={s002, s003};
  oop->add(twoStudents, twoStudents+2);
  ASSERT_EQ(2, oop->size());
//   ASSERT_EQ(-1, s002->getScore("Object-oriented Programming"));
//   ASSERT_EQ(-1, s003->getScore("Object-oriented Programming"));
//
//   // adding two grads
//   Student * twoGStudents[]={g001, g002};
//   oop->add(twoGStudents, twoGStudents+2);
//   ASSERT_EQ(4, oop->size());
//   ASSERT_EQ(-1, g001->getScore("Object-oriented Programming"));
//   ASSERT_EQ(-1, g002->getScore("Object-oriented Programming"));
}
//
// TEST (CourseTest, getStudentsByNameInc) {
//   // Test data
//   Student * s001 = new Undergrad("U2018EECS001", "John");
//   Student * s002 = new Undergrad("U2018EECS002", "Mary");
//   Student * s003 = new Undergrad("U2018EECS003", "Nick");
//   Student * g001 = new Grad("G2018CSIE001", "Mike");
//   Student * g002 = new Grad("G2018CSIE002", "Jane");
//   Course * oop = new Course ("EECS201", "Object-oriented Programming");
//
//   Student * Students[]={s001, s002, s003, g001, g002};
//   oop->add(Students, Students+5);
//
//   // get students by names in increasing alphabetical order
//   std::vector<Student *> namesAlphabeticalInc = oop->getStudentsByNameInc();
//   ASSERT_EQ("Jane", namesAlphabeticalInc[0]->name());
//   ASSERT_EQ("John", namesAlphabeticalInc[1]->name());
//   ASSERT_EQ("Mary", namesAlphabeticalInc[2]->name());
//   ASSERT_EQ("Mike", namesAlphabeticalInc[3]->name());
//   ASSERT_EQ("Nick", namesAlphabeticalInc[4]->name());
// }
//
// TEST (CourseTest, SetScore) {
//   // Test data
//   Student * s001 = new Undergrad("U2018EECS001", "John");
//   Student * s002 = new Undergrad("U2018EECS002", "Mary");
//   Student * s003 = new Undergrad("U2018EECS003", "Nick");
//   Student * g001 = new Grad("G2018CSIE001", "Mike");
//   Student * g002 = new Grad("G2018CSIE002", "Jane");
//   Course * oop = new Course ("EECS201", "Object-oriented Programming");
//
//   Student * Students[]={s001, s002, s003, g001, g002};
//   oop->add(Students, Students+5);
//
//
//   // set scores of students in oop course
//
//   // these are the students
//   std::vector<std::string> ids = {"U2018EECS001","U2018EECS002", "U2018EECS003", "G2018CSIE001", "G2018CSIE002"};
//   // these are their corresponding scores
//   std::vector<int> scores = {90, 50, 85, 68, 90};
//
//   // setting scores of students
//   // hint: use find_if to search the students with ID
//   // once you find it, call setScore on the student found
//   oop->setScores(ids, scores);

  // expect each student to get his/her oop score
  // ASSERT_EQ(90, s001->getScore(oop->name()));
  // ASSERT_EQ(50, s002->getScore(oop->name()));
  // ASSERT_EQ(85, s003->getScore(oop->name()));
  // ASSERT_EQ(68, g001->getScore(oop->name()));
  // ASSERT_EQ(90, g002->getScore(oop->name()));
// }

// TEST (CourseTest, failedStudents) {
//   // Test data
//   Student * s001 = new Undergrad("U2018EECS001", "John");
//   Student * s002 = new Undergrad("U2018EECS002", "Mary");
//   Student * s003 = new Undergrad("U2018EECS003", "Nick");
//   Student * g001 = new Grad("G2018CSIE001", "Mike");
//   Student * g002 = new Grad("G2018CSIE002", "Jane");
//   Course * oop = new Course ("EECS201", "Object-oriented Programming");
//
//   Student * Students[]={s001, s002, s003, g001, g002};
//   oop->add(Students, Students+5);
//
//   std::vector<std::string> ids = {"U2018EECS001","U2018EECS002", "U2018EECS003", "G2018CSIE001", "G2018CSIE002"};
//   std::vector<int> scores = {90, 50, 85, 68, 90};
//   oop->setScores(ids, scores);
//
//
//   // getting the list of failed students
//   std::vector<Student *> fs = oop->failedStudents();
//   ASSERT_EQ(2, fs.size());
//   // undegrad fails if score is less than 60
//   ASSERT_EQ(50, fs[0]->getScore("Object-oriented Programming"));
//   // grad fails if score is less than 70
//   ASSERT_EQ(68, fs[1]->getScore("Object-oriented Programming"));
// }
