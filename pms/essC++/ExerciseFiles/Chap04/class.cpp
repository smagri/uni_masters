// class.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// a very simple class
//
// This is class 'Interface'.
// class Class1 {
//     int i = 0;
// public:
//     void setvalue( const int value ) { i = value; }
//     int getvalue() const { return i; }
// };

// This is class 'Implementation', one should sperate into two files
// the interface and implementaion of a class.  So split Class1 above
// like this.
//
// Were  declaration of  class member  data and  functions are  in the
// interface file or the .h file.   And the definition of class member
// data  and functions  are in  the other  file, .cpp  file, with  the
// function definitions.



// class declaration, interface, 'the class'.
//
// Object member fns use keyword this, it is a ptr to the current
// object.
//
class Class1 {
  // int i = 0; only in -std=c++11 or -std=gnu++11
  //
  // No constructor  and destructor  defined, hence the  implicit ones
  // are included in the class by default.
  //
  // 
  int i;
 public:
  void setvalue(const int value);
    int getvalue() const; 
};

// class definition, implementation
void Class1::setvalue( const int value ){
  i = value;
}

int Class1::getvalue() const{

  //fprintf(stderr, "this pointer value is=%p\n", object1.getvalue());

  // Printout the value of the 'this 'ptr, the pointer to the current
  // object.
  //
  // this ptr is useful when overloading an assignment operator to
  // pass a reference to the current object
  //
  fprintf(stderr, "this pointer value is=%p\n", this);
  

  return i;
}



// You could make i public instead of the default private, this will
// allow you to access it with object1.i in main below.  However, of
// private you can't do this.
//
// Also, main() is usually in a seperate file, main.cpp.
int main( int argc, char ** argv ) {

  int i = 47;
  
  // Instance of the class == object, implicit default constructor used.
  Class1 object1;
  Class1 object2;
    
  object1.setvalue(i);
  object2.setvalue(i);
  fprintf(stderr, "value is %d\n", object1.getvalue());
  fprintf(stderr, "address of object1 is value is %p\n", &object1);
  fprintf(stderr, "value is %d\n", object2.getvalue());
  fprintf(stderr, "address of objec2t is value is %p\n", &object2);

  return 0;
}
