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

//  RAND_MAX = (double) 8;
}


Random::~Random(){

  // destructor
  
}


//int Random::genRandNum(int randNumRay[]){
int Random::genRandNum(double randNumRay[]){

  // Generates random numbers based on seed, and stores them in the
  // integer array randNumRay, passed from main.


  //int randNumRay[N_];; // each element containds current random number
			 // returned by rand()
  int i;
  double num;

  // Initialise random seed for sucessive calls to rand().
  srand(seed_);

  for (i=0; i<N_; i++){
    // Returns pseudo-random integral numbers in the range between 0 and
    // RAND_MAX(a constant defined in <cstdlib>).
    //
    // wrks: for ints randNumRay[i] = rand() % 10 + 1;
    num = ((double) rand()) / RAND_MAX;
    randNumRay[i] = 0.2 + num * (8 - 0.2);
  }

  //fprintf(stderr, "random.cpp: genRandNum(), i=%d\n", i);
  return num;
}

void Random::setNumRands2gen(int numRands2gen){

  N_ = numRands2gen;
  
}

void Random::setSeed(unsigned int seed){

  seed_ = seed;
  
}




 
