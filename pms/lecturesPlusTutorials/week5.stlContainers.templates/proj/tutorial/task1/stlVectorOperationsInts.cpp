#include <vector>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

//
// task 1: STL Vector Operations
//

// @end modify the code to use integers instead.

int populateVec(vector<int> &randomNumVec){

  int numValues; // Number of values in the vector during this invocation.
  
  // Construct a trivial random generator engine from a time-based
  // seed.  All <random> library functions need a seed.  And generate
  // pseudo random numbers.
  //
  // As an alternative trivial random numbers can also be generated
  // using cstdlib funs rand and srand.
  //
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  // In a uniform distribution values are in the range a<=x<b, ie
  // [a,b).  More specifically this is 0<=x<10 for this code.
  //
  // Uniform distribution of int's, gives number of random values to
  // generate with the normal/Gaussian distribution, in this fn
  // invocation.
  std::uniform_int_distribution<int> distributionUniform(0, 10);

  // Normal/Gaussian distributions, which has mean=8 and std deviation=4.
  //
  std::normal_distribution<double> distributionGaussian(8.0, 4.0);

  // Fill Vector:
  // Vector size is given by the Uniform Distribution.
  // Vector values come from the Normal/Gaussian Distribution.
  numValues = distributionUniform(generator);
  cout << "Fill Vector with " << numValues << " values:" << endl;
  cout << "Fill Vector with random numbers from a Gaussian(aka Normal), " <<
    "distribution, where:" << endl;
  cout << " mean=8.0, standard deviation=4.0:" << endl;
  for (int i=0; i<numValues; i++){
    randomNumVec.push_back( distributionGaussian(generator) );
    cout << "randomNumVec.at(" << i << ")=" << randomNumVec.at(i) << endl;
  }
  
  return 0;
    
};


void printValues(vector<int> &randomNumVec){

  cout << "in printValues:" << endl;

  // long hand for the first time.
  vector<int>::iterator it;
  vector<int>::iterator itbegin = randomNumVec.begin();
  vector<int>::iterator itend = randomNumVec.end();

  for (it=itbegin; it<itend; it++){
    cout << *it << " ";
  }
  cout << endl;
  
};


int bubbleSortVec(vector<int> &randomNumVec){
  // Rearange vector elements using the bubble sort algorithm.

  int n = randomNumVec.size();
  bool swapped = true;
  double tempVal; // holding place for swapped element

  while (swapped){
    // Once a whole pass without any swap occures we are 'bubble'
    // sorted.
    swapped = false;
      
    for (int i=1; i<n; i++){
      // if this pair is out of order
      if (randomNumVec.at(i-1) > randomNumVec.at(i)){
	  // swap them and remember something changed
	tempVal = randomNumVec.at(i);
	randomNumVec.at(i) = randomNumVec.at(i-1);
	randomNumVec.at(i-1) = tempVal;
	swapped = true;
      }
    }
    
  } // while (swapped)
  
	    
  return 0;
  
};



int main(int argc, char ** argv){

  // vector<double> goes to vector<int>, kind of like a cast I think???
  
  vector<int> randomNumVec;

  // Pass by reference => modifies main's copy within the given
  // function.
  //
  populateVec(randomNumVec);
  printValues(randomNumVec);
  
  bubbleSortVec(randomNumVec);
  printValues(randomNumVec);
  
  return 0;
  
};


