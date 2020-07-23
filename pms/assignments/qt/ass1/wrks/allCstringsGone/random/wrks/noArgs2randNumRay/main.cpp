

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "random.h"


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;


int main(int argc, char *argv[]){

  unsigned int seed; // seed for random number generator rand()
  int numRands2gen;  // number of random numbers to generate
  int randNumRay[10];    // array containg random numbers

  fprintf(stderr, "main.cpp, in main() of class Random:\n\n");
  
  // Create instance of class random, called smRandom, also,
  // initialiase private member data.
  //
  // Seed is  initialised to  a distinctive  runtime value,  ie return
  // value  of time(),  this gives  random-like numbers.   ie seed  is
  // initialised to  a value representing the  current time(or program
  // calling time).
  seed = time(NULL);
  numRands2gen = 10;
  Random smRandom(seed, numRands2gen);

  fprintf(stderr, "randNumRay() called:\n");
  smRandom.randNumRay();
  
  fprintf(stderr, "\nrandNumRay() called:\n");
  smRandom.setNumRands2gen(12);
  smRandom.randNumRay();
  
  // seed = 1; numRands2gen = 1;
  // smRandom.setWidthHeight(width, height);
  // fprintf(stderr, "\nset width=%d, height=%d:\n", width, height);
  // fprintf(stderr, "area of random=%d\n", smRandom.getArea());
  // fprintf(stderr, "perimiter of random %d\n", smRandom.getPerimeter());

  
  return 0;
}
