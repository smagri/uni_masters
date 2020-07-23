

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "random.h"


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;


int main(int argc, char *argv[]){

  int width, height;

  // create instance of class random, called smRandom, also,
  // initialiase private member data
  Random smRandom(1, 1);  
  
  fprintf(stderr, "main.cpp, in main() of class Random:\n\n");
    
 
  // seed = 1; numRands2gen = 1;
  // smRandom.setWidthHeight(width, height);
  // fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
  // fprintf(stderr, "area of random=%d\n", smRandom.getArea());
  // fprintf(stderr, "perimiter of random %d\n", smRandom.getPerimeter());

  
  return 0;
}
