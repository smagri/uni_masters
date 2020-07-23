//
// Random Class declaration.
//

#ifndef RANDOM_H_
#define RANDOM_H_

using namespace std; // allow used of <st


class Random{

 // Access specifier 'public:', these variables and functions are
 // available to all other classes that inherit(?)from this class.
 public:
  Random(int seed, int numRands2gen); // class constructor
  ~Random();// class destructor

  // void => return nothing or no parameters passed.
  void setSeed(int seed);
  void setNumRands2gen(int numRands2gen);
  int randNumRay(int iray, int numRands2gen);

  
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
 private:
  int seed_; // seed for random number generator
  int N_;    // number of random numbers that are generated each time	
  
};


#endif // RANDOM_H_
