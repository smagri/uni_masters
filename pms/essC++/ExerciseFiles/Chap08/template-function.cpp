// template-function.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// T is template type, and is the only item in the argument list
// here. So here maxof is the function that return a type T and also
// takes type T as arguments.
//
//
// Use keyword typename not class, class is ambiguous but there is a
// lot of legacy code that uses it.
template <typename T> T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

int main( int argc, char ** argv ) {
  // Template fn called here, with type int.  That is wherever you see
  // a T is the template above replace it with int.
  //
  // Thus the compiler generates a specialisation of the function
  // using type int.  Always use the <type> here as you may get
  // undesirable results otherwise. <int> is the template argument
  // list.
  printf("max is: %d\n", maxof<int>( 7, 9 ));
  
  return 0;
}
