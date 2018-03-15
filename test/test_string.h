#include "../src/vector_io.h"
#include <string>
TEST (string, c_str){
  char cs[]="hello, string!";
  ASSERT_EQ('h',cs[0]);
  ASSERT_EQ('!',cs[13]);
  ASSERT_EQ('\0',cs[14]);
  ASSERT_EQ(15,sizeof(cs)/sizeof(char));
}

TEST (string, string){
  std:: string cpps("hello, string!");
  ASSERT_EQ('h',cpps[0]);
  ASSERT_EQ('!',cpps[13]);
  ASSERT_EQ('\0',cpps[14]);
  ASSERT_EQ(14,cpps.length());
}

TEST (string, pullvectorfromstring){
  std:: string s("2 [1,2]");
  int dim;
  double* vec;
  vec=pullvectorfromstring(s,&dim);
  ASSERT_EQ(2,dim);
  ASSERT_NEAR(1,vec[0],0.0001);
  ASSERT_NEAR(2,vec[1],0.0001);
}

TEST (string, pullvectorfromstring_2){
  std:: string s("3 [1,2,3]");
  int dim;
  double* vec;
  vec=pullvectorfromstring(s,&dim);
  ASSERT_EQ(3,dim);
  ASSERT_NEAR(1,vec[0],0.0001);
  ASSERT_NEAR(2,vec[1],0.0001);
  ASSERT_NEAR(3,vec[2],0.0001);
  delete [] vec;
}

TEST (string, stringlenth){
  std:: string s("testing string length");
  ASSERT_EQ(21,s.length());
}

TEST (string, stringempty){
  std:: string s("");
  ASSERT_TRUE(s.empty());
}

TEST (string, stringclear){
  std:: string s("testing string clear");
  s.clear();
  ASSERT_EQ("",s);
}

TEST (string, stringinsert){
  std:: string s("testing");
  s.insert(7," string insert");
  ASSERT_EQ("testing string insert",s);
}

TEST (string, stringcopy){
  std:: string s1("testing string copy");
  char s2[20];
  s1.copy(s2,4,15);
  s2[4]='\0';
  ASSERT_STREQ("copy",s2);
}

TEST (string, stringcompare){
  std:: string s("testing string compare");
  ASSERT_TRUE(s.compare(14,7,"compare"));
}

TEST (string, stringswap){
  std:: string s1("string1");
  std:: string s2("string2");
  s1.swap(s2);
  ASSERT_EQ("string2",s1);
  ASSERT_EQ("string1",s2);
}

TEST (string, stringfind){
  std:: string s1("testing string find");
  std:: string s2("i dont like to eat apple");
  ASSERT_TRUE(s1.find("string"));
  ASSERT_TRUE(s2.find("apple"));
}

TEST (string, stringoperator_1){
  std:: string s1("http://");
  std:: string s2("www.ntut.");
  std:: string s3("edu.org.tw");
  std:: string url=s1+s2+s3;
  ASSERT_EQ("http://www.ntut.edu.org.tw",url);
}

TEST (string, stringoperator_2){
  std:: string s1("http://");
  s1 += "www.ntut.";
  s1 += "edu.org.tw";
  ASSERT_EQ("http://www.ntut.edu.org.tw",s1);
}
