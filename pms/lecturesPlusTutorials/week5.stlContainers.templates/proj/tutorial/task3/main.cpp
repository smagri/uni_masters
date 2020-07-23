//
// task3: Using Template Fuctions
//

#include <cstdio>
#include <iostream>
#include <vector>

#include "student.h"


// T  is template  type, and  is the  only item  in the  argument list
// here. So  here bubleSortVec is the  function that returns a  type T
// and also takes type T as arguments.

// template <typename T> int bubbleSortVec(vector<T>){
// }


// T = int
// T = double
// T = char
// T = string
// T = Student * ??? vs GroupA *, GroupB *... all with same member fns???
//
template <typename T> int bubbleSortVec(vector<T> &nameVec){

  // Rearange vector elements using the bubble sort algorithm.

  int n = nameVec.size();
  bool swapped = true;
  //double tempVal; // holding place for swapped element
  T tempVal; // holding place for swapped element(is it necessary?

  while (swapped){
    // Once a whole pass without any swap occures we are 'bubble'
    // sorted.
    swapped = false;
      
    for (int i=1; i<n; i++){
      // if this pair is out of order
      if (nameVec.at(i-1) > nameVec.at(i)){
          // swap them and remember something changed
        tempVal = nameVec.at(i);
        nameVec.at(i) = nameVec.at(i-1);
        nameVec.at(i-1) = tempVal;
        swapped = true;
      }
    }
    
  } // while (swapped)
  
  return 0;
}; 


// Template for bubble sorting a Student class vector, or any vector that as a:
// getMemberId() and setMemberId() member functions.
// 
//
// T = int
// T = double
// T = char
// T = string
// T = Student * ??? vs GroupA *, GroupB *... all with same member fns???
//
template <typename T> int bubbleSortGroup(vector<T> &nameVec){

  // Rearange vector elements using the bubble sort algorithm.
  // T  is a pointer to a Student class, or <Student *>.
  //
  // This is a class agnostic fn???
  // ie <Student *>, <GroupA *>, <GroupB *>...but each group must have the same
  // member fns???
  //
  // I could do a similar sort by string and surname, that would be
  // another template fn.
  //
  int n = nameVec.size();
  bool swapped = true;
  //double tempVal; // holding place for swapped element
  //Student *tempVal; // holding place for swapped element(is it necessary?
  //T tempVal;
  int tempVal;
  string strtempVal;
  
  while (swapped){
    // Once a whole pass without any swap occures we are 'bubble'
    // sorted.
    //fprintf(stderr, "dbg: in while loop\n");
    swapped = false;
      
    for (int i=1; i<n; i++){
      // if this pair is out of order
      if (nameVec.at(i-1)->getMemberId() > nameVec.at(i)->getMemberId()){
	// swap them and remember something changed
	//fprintf(stderr, "dbg: in if comparision\n");

	//tempVal->setMemberId(nameVec.at(i)->getMemberId());
	//fprintf(stderr, "tempVal->getMemberId()=%d\n",tempVal->getMemberId());
	tempVal = nameVec.at(i)->getMemberId();
	strtempVal = nameVec.at(i)->getMemberSurname();
	//fprintf(stderr, "dbg: tempVal=%d\n", tempVal);
	
        nameVec.at(i)->setMemberId(nameVec.at(i-1)->getMemberId());
	nameVec.at(i)->setMemberSurname(nameVec.at(i-1)->getMemberSurname());
        //nameVec.at(i-1)->setMemberId(tempVal->getMemberId());
	nameVec.at(i-1)->setMemberId(tempVal);
	nameVec.at(i-1)->setMemberSurname(strtempVal);
	
        swapped = true;
      }
    }
    
  } // while (swapped)
  
  return 0;
};



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
  
  
  //fprintf(stderr, "main: creating main.\n");

  Student sMe; // executes default constractor, no params or return value
  Student s1(11797724, "Newton");
  Student s2(11797725, "De Horta");
  Student s3(11797726, "Maybour");
  Student s4(11797727, "Saule");
  Student s5(11797728, "Vagg");

  
  // Create a vector of pointers to the class Student.
  vector<Student *> studentVec = {&s5, &s4, &s3, &s2, &s1, &sMe};


  // Testing bubbleSortVec() template fn:
  //
  fprintf(stderr, "\nTesting buubleSortVec() template fn:\n");

  vector<int> vi = {1, 5, 3, 4};
  vector<double> vd = {1.1, 5.1, 3.1, 4.1};
  vector<char> vc = {'m', 'z', 'l', 'n', 'a'};
  vector<string> vs={"Maybour", "Vagg", "Magri", "Newton","De Horta", "Saule"};

  
  fprintf(stderr, "\nBubbleSortVec(vector<ints>):\n");
  
  fprintf(stderr, "Unsorted:\n");
  for (int i=0; i<vi.size(); i++){
    cout << vi.at(i) << " ";
  }
  cout << endl;
  
  bubbleSortVec(vi);

  fprintf(stderr, "Sorted:\n");
  for (int i=0; i<vi.size(); i++){
    cout << vi.at(i) << " ";
  }
  cout << endl;

  
  fprintf(stderr, "\nBubbleSortVec(vector<double>):\n");

  fprintf(stderr, "Unsorted:\n");
    for (int i=0; i<vd.size(); i++){
    cout << vd.at(i) << " ";
  }
  cout << endl;
  
  bubbleSortVec(vd);

  fprintf(stderr, "Sorted:\n");
  for (int i=0; i<vd.size(); i++){
    cout << vd.at(i) << " ";
  }
  cout << endl;
  

  // If you use T=int instead of T=char integers are output instead of
  // the actual characters.
  fprintf(stderr, "\nBubbleSortVec(vector<char>):\n");

  fprintf(stderr, "Unsorted:\n");
  for (int i=0; i<vc.size(); i++){
    cout << vc.at(i) << " ";
  }
  cout << endl;
  
  bubbleSortVec(vc);

  fprintf(stderr, "Sorted:\n");
  for (int i=0; i<vc.size(); i++){
    cout << vc.at(i) << " ";
  }
  cout << endl;

  fprintf(stderr, "\nBubbleSortVec(vector<string>):\n");

  fprintf(stderr, "Unsorted:\n");
  for (int i=0; i<vs.size(); i++){
    cout << vs.at(i) << " ";
  }
  cout << endl;
  
  bubbleSortVec(vs);

  fprintf(stderr, "Sorted:\n");
  for (int i=0; i<vs.size(); i++){
    cout << vs.at(i) << " ";
  }
  cout << endl;


  
  fprintf(stderr, "\nUnsorted Students:\n");
  printStudents(studentVec);

  
  fprintf(stderr, "\nUse Bubble Sort?...y or n...");
  fscanf(stdin, "%s", tmpCstr);
  bubbleSort = tmpCstr; // cStr is input, now convert to cpp string.
  
  if (bubbleSort == "y"){
  //   // Sort, using bubble sort algorithm by ID or Surname.
  //   bubbleSortVec(vector<Student *> studentVec){
    bubbleSortGroup(studentVec);
    fprintf(stderr, "\nBubble Sorted Students:\n");
  }
  else{
    fprintf(stderr, "\nUser did not request sorting, Unsorted Students:\n");
  }

  printStudents(studentVec);


  
  return 0;
  
};



  
