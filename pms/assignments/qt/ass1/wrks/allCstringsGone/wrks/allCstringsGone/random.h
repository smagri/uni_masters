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
  Random(); // class default constructor
  Random(unsigned int seed, int numRands2gen); // class constructor
  ~Random();// class destructor

  void setNumRands2gen(int numRands2gen);
  void setSeed(unsigned int seed);

  // virtual => fn can be overloaded in the derived classes.
  virtual int genRandNum(double randNumRay[]);

  
  // Access specifier 'private:', these variables and functions are only
  // available to member functions/class methods.
 private:
  unsigned int seed_; // seed for random number generator
  int N_;    // number of random numbers that are generated each time	
  
};


#endif // RANDOM_H_
