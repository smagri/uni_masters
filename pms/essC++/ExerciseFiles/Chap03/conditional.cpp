// conditional.c by Bill Weinman <http://bw.org/>
#include <cstdio>

// conditional compilation, commonly used for different versions of
// code, for debugging or for supporting different target environments
#define FOO

#include "conditional.h"



int main( int argc, char ** argv ) {

  fprintf(stderr, "Number is %d\n", NUMBER);
  
  return 0;
  
}
