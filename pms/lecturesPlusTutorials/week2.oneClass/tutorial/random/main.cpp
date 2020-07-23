

// system include files
#include <iostream>
#include <cstdio>


// non-system  include files
#include "random.h"


#define MAX_randNumRay_SIZE 10


// so you can refer to std class member function just by their name,
// thus with no std:: prefix
using namespace std;



int main(int argc, char *argv[]){

  unsigned int seed; // seed for random number generator rand()
  int numRands2gen;  // number of random numbers to generate
  int randNumRay[MAX_randNumRay_SIZE];// array containg random numbers
  int i;

  
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
  fprintf(stderr, "(seed=%d, numRands2gen=%d)\n", seed, numRands2gen);
  Random smRandom(seed, numRands2gen);

  fprintf(stderr, "randNumRay() called:\n");
  smRandom.genRandNum(randNumRay);
  for (i=0; i<MAX_randNumRay_SIZE; i++){
    fprintf(stderr, "random num %d=%d\n", i, randNumRay[i]);     
  }

  
  fprintf(stderr, "\nrandNumRay() called:\n");
  seed = 10;
  numRands2gen = 7;
  fprintf(stderr, "(seed=%d, numRands2gen=%d)\n", seed, numRands2gen);
  smRandom.setSeed(seed);
  smRandom.setNumRands2gen(numRands2gen);
  smRandom.genRandNum(randNumRay);
  for (i=0; i<numRands2gen; i++){
    //for (i=0; i<rnrSize; i++){
    fprintf(stderr, "random num %d=%d\n", i, randNumRay[i]);     
  }

  fprintf(stderr, "\nrandNumRay() called:\n");
  seed = time(NULL);
  numRands2gen = 10;
  fprintf(stderr, "(seed=%d, numRands2gen=%d)\n", seed, numRands2gen);
  smRandom.setSeed(seed);
  smRandom.setNumRands2gen(numRands2gen);
  smRandom.genRandNum(randNumRay);
  for (i=0; i<numRands2gen; i++){
    //for (i=0; i<rnrSize; i++){
    fprintf(stderr, "random num %d=%d\n", i, randNumRay[i]);     
  }
    
  
  // fprintf(stderr, "\nrandNumRay() called:\n");
  // seed = 100;
  // numRands2gen = 35;
  // fprintf(stderr, "(seed=%d, numRands2gen=%d)\n", seed, numRands2gen);
  // smRandom.setSeed(seed);
  // smRandom.setNumRands2gen(numRands2gen);
  // smRandom.genRandNum(randNumRay);
  // for (i=0; i<numRands2gen; i++){
  //   //for (i=0; i<rnrSize; i++){
  //   fprintf(stderr, "random num %d=%d\n", i, randNumRay[i]);     
  // }
  
  return 0;
}
