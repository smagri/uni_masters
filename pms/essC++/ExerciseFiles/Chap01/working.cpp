// working.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string>
using namespace std;

int main( int argc, char ** argv ){

  // using the range-based for loop
  //
  //  A  more  efficient  way  to  itterate over  the  elements  of  a
  //  container(works for STL containers like string.
  //
  //  Compile time feature, so it knows the size of the container, int
  //  array here does not need to be terminated.
  
  int a[] = {1, 2, 3, 4, 5}; // container is a, an array of integers


  // applied to an array of integers
  fprintf(stderr, "\nfor range-based loop applied to an array or integers:");

  // i  is the  variable that  contains  the elements  of container  a
  // during the loop.
  //
  //
  //int i=0;
  for (int i: a){
//    fprintf(stderr, "element a[%d]=%d\n", i++, aElement);
    fprintf(stderr, "element is %d\n", i);
  }
  
  
  return 0;
}

