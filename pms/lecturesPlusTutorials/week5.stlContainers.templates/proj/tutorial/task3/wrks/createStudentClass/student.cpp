//
// Student class implementation:
//

#include "student.h"



Student::Student():id_(11797723), surname_("Magri"){

  // Constructor initialisation to member=me.
  
}


// Student::~Student(){

//   // Default destructor, no parameters or return values.
  
// }


void Student::setMemberId(int id){

  id_ = id;

}


void Student::setMemberSurname(string surname){

  surname_ = surname;

}


int Student::getMEmberId(void){

  return id_;
}


string Student::getMemberSurname(void){

  return surname_;
}
