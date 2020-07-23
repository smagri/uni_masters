//
// task3: Using Template Fuctions
//

#include <cstdio>
#include <iostream>
#include <vector>

#include "student.h"


// int bubbleSortVec(vector<int> &nameVec){

// // Rearange vector elements using the bubble sort algorithm.

//   int n = nameVec.size();
//   bool swapped = true;
//   //double tempVal; // holding place for swapped element
//   int tempVal; // holding place for swapped element(is it necessary?

//   while (swapped){
//     // Once a whole pass without any swap occures we are 'bubble'
//     // sorted.
//     swapped = false;
      
//     for (int i=1; i<n; i++){
//       // if this pair is out of order
//       if (nameVec.at(i-1) > nameVec.at(i)){
//           // swap them and remember something changed
//         tempVal = nameVec.at(i);
//         nameVec.at(i) = nameVec.at(i-1);
//         nameVec.at(i-1) = tempVal;
//         swapped = true;
//       }
//     }
    
//   } // while (swapped)
  
            
//   return 0;
  
// };





void printStudents(vector<Student *> &studentVec){

  // Iterrate  over  the  Student  class  vector  to  print  out  it's
  // elements, or each student's identifiers.

  vector<Student *>::iterator it;   // vector iterator
  vector<Student *>::iterator itbegin = studentVec.begin();
  vector<Student *>::iterator itend = studentVec.end();
  //
  // method one:
  for (it=itbegin; it<itend; it++){
    // it, is a pointer to an element in the vector.
    //
    // *it, is the  contents of that pointer,  the element value(could
    // be say  an int or double...etc),  in this case this  is another
    // pointer, use -> to deference that pointer.
    //
    // In this case (*it)-> is the pointer to a Student class.
    //cout << "Student id is " << (*it)->getMemberId() << "; ";
    //cout << "Surname is " << (*it)->getMemberSurname() << endl;
  }

  // method2 two:
  for (int i=0; i<studentVec.size(); i++){
    // studentVec.at(i) is an element in the vector.  In this case
    // each element in the studentVec vector is a pointer to a Student
    // class instance.  Use -> to dereference that pointer.
    cout << "Student id is " << studentVec.at(i)->getMemberId() << "; ";
    cout << "Surname is " << studentVec.at(i)->getMemberSurname() << endl;
  }
  
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



int main(int argc, char ** argv){


  char tmpCstr[1]; // temporary c string for conversions of cppString=cString
  string bubbleSort; // y or n are recognised
  
  
  fprintf(stderr, "main: creating main.\n");

  Student sMe; // executes default constractor, no params or return value
  Student s1(11797724, "Newton");
  Student s2(11797725, "De Horta");
  Student s3(11797726, "Maybour");
  Student s4(11797727, "Saule");
  Student s5(11797728, "Vagg");

  
  // Create a vector of pointers to the class Student.
  vector<Student *> studentVec = {&s5, &s4, &s3, &s2, &s1, &sMe};


  fprintf(stderr, "Unsorted Students:\n");
  printStudents(studentVec);


  
  fprintf(stderr, "Use Bubble Sort?...y or n...");
  fscanf(stdin, "%s", tmpCstr);
  bubbleSort = tmpCstr; // cStr is input, now convert to cpp string.
  
  if (bubbleSort == "y"){
  //   // Sort, using bubble sort algorithm by ID or Surname.
  //   bubbleSortVec(vector<Student *> studentVec){
    fprintf(stderr, "\nBubble Sorted Students:\n");
  }
  else{
    fprintf(stderr, "\nUser did not request sorting, Unsorted Students:\n");
  }

  printStudents(studentVec);


  
  return 0;
  
};



  
