//
// Random class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//

//#include <iostream>
#include <cstdio>
#include <stdlib.h>     /* srand, rand */
//#include <time.h>       /* time */
#include <ctime>       /* time */


#include "random.h"


Random::Random(){

}


Random::Random(unsigned int seed, int numRands2gen){

  seed_ = seed; // initial random seed value
  N_ = numRands2gen;

  srand(seed_); // setup seed for subsequent calls to rand()
  
}


Random::~Random(){

  // destructor
  
}


int Random::genRandNum(int randNumRay[]){

  // Generates random numbers based on seed, and stores them in the
  // integer type array randNumRay, passed from main.

  // The random numbers generated in this function are integers.
  
  //int randNumRay[N_];; // each element containds current random number
                         // returned by rand()
  int i;
  

  // Initialise random seed for sucessive calls to rand().
  srand(seed_);

  for (i=0; i<N_; i++){
    // Returns pseudo-random integral numbers between 0 and RAND_MAX.
    //
    randNumRay[i] = rand() % 10 + 1;
  }

  fprintf(stderr, "returns from genRandNum(), i=%d\n", i);

}


int Random::genRandNum(double randNumRay[], double fMin, double fMax){

  // Generates random numbers based on seed, and stores them in the
  // double type array randNumRay, passed from main.

  // The random numbers generated in this function are of type double.
  // These values are in the range of fMin to fMax.
  
  int i;
  double num; // temporary double number


  for (i=0; i<N_; i++){
    num = ((double) rand()) / RAND_MAX;
    randNumRay[i] = fMin + (num * (fMax - fMin));
  }
  //fprintf(stderr, "random.cpp: genRandNum(), i=%d\n", i);

  return num;
}


void Random::setNumRands2gen(int numRands2gen){

  N_ = numRands2gen;
  
}

void Random::setSeed(unsigned int seed){

  seed_ = seed;

  srand(seed_); // setup seed for subsequent calls to rand()
  
}




 
