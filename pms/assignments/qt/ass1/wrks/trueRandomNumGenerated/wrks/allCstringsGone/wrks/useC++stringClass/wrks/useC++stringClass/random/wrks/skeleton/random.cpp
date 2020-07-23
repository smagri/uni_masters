//
// Random class implementation.
//
// 
// Class functions or methods(aka member functions) are defined here.
//

//#include <iostream>
#include <cstdio>

#include "random.h"


Random::Random(int seed, int numRands2gen){

  seed_ = seed;
  N_ = numRands2gen;
}


Random::~Random(){

  // destructor
  
}


void Random::setSeed(int seed){

  seed_ = seed;
  
}

void Random::setNumRands2gen(int numRands2gen){

  N_ = numRands2gen;
  
}

int Random::randNumRay(int iray, int numRands2gen){

  N_ = numRands2gen;
  
}


 
