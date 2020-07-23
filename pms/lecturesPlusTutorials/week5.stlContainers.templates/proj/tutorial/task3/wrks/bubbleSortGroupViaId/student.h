//
// Student class definiton:
//

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std; // allow use as std::



class Student{

 public:
  
  Student();
  Student(int id, string surname);
  //~Student();

  void setMemberId(int id);
  void setMemberSurname(string surname);
  int getMemberId(void);
  string getMemberSurname(void);

  void printStudents(vector<Student *> &studentVec);
  
 private:

  int id_;
  string surname_;
  
  
};



#endif // STUDENT_H_
