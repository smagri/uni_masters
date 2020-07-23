// function-object.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// functor, overloading the fn operator you create a class that
// operates as if it were a fn

// good for  keeping state or other context info with your fn calls

//




class MultBy {
    int mult = 1;
  MultBy(); //private default constructor, thus must pass integer to
	    //construct the object
public:
    MultBy ( int n ) : mult(n) {}
  // fn operator overload
  // () is the fn operator, takes one parameter
  // returns an int
  // operator keyword
  //
  // The function operator is a good way to create an object that
  // works like a fn.  ie function is executed when object is created?
  // It keeps state and other info between fn calls, see examples in
  // STL section later.
  int operator () ( int n ) const { return mult * n; }
};

int main( int argc, char ** argv ) {

  // times4(4) where 4 is the multiplier, mult=4
  const MultBy times4(4);
  //
  const MultBy times10(10); // multiplier = mult = 10
  const MultBy times15(15); // multiplier = mult = 15

  // fn overload means 4 * 5
  // ie mult=4 and n=5
  // fn multipies mult * n
  printf("times4(5) is %d\n", times4(5));
  //
  printf("times4(15) is %d\n", times4(15));
  printf("times10(5) is %d\n", times10(5));
  printf("times10(15) is %d\n", times10(15));
  printf("times15(5) is %d\n", times15(5));
  printf("times15(15) is %d\n", times15(15));
    
    return 0;
}
