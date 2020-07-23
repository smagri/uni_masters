//
// Student class implementation:
//
#include <vector>
#include <iostream>

#include "student.h"



Student::Student():id_(11797723), surname_("Magri"){

  // Default Constructor initialisation to member=me.
  
}

Student::Student(int id, string surname){

  // Initialisation Constructor.

  id_ = id;

  surname_ = surname;
  
  
}


// Student::~Student(){

//   // Default destructor, no parameters or return values.
  
// }


void Student::setMemberId(int id){

  // put id into a vector?
  id_ = id;

}


void Student::setMemberSurname(string surname){

  // put surname into a vector?
  surname_ = surname;

}


int Student::getMemberId(void){

  return id_;
}


string Student::getMemberSurname(void){

  return surname_;
}


//void printStudents(vector<int>, vector<string>){

  // Iterrate  over both  vectors  at  the same  time,  and print  the
  // student id and student surname with each itteration.
  
  //fprintf(stderr, "Student id:\n", id_);
  //fprintf(stderr, "Student surname:\n", surname_);
  
//}


