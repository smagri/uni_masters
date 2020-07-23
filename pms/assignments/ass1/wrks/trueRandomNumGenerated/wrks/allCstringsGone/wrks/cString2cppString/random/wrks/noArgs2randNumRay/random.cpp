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



Random::Random(unsigned int seed, int numRands2gen){

  seed_ = seed; // initial random seed value
  N_ = numRands2gen;
  
}


Random::~Random(){

  // destructor
  
}


int Random::randNumRay(){

  // Returns a pseudo-random integral number in the range between 0 and
  // RAND_MAX(a constant defined in <cstdlib>, for fn rand();

  int i;
  int randNumRay[N_];; // each element containds current random number
		 // returned by rand()
//  int curRandNum; // current random number returned by rand()

  // Initialise random seed for sucessive calls to rand().
  srand(seed_);

  for (i=0; i<N_; i++){
    randNumRay[i]= rand() % 10 + 1;
    fprintf(stderr, "random num %d=%d\n", i, randNumRay[i]);   
  }


  // int rand(N_);
}


// void Random::setSeed(unsigned int seed){

//   // For every new seed value the successive call to rand() returns
//   // different results.  So same seed => same rand() results.
//   //
//   // If seed is set to 1, the generator is reinitialised and produces
//   // result before _any_ call to rand()/srand().
//   seed_ = seed;
  
// }


void Random::setNumRands2gen(int numRands2gen){

  N_ = numRands2gen;
  
}




 
