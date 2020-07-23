// numword-test.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <cstdint>

#include "numword.h"

using namespace std;


// writing own class to get a better feal for c++

// numwords, a class that converts numbers into words

// interface in numword.h, class definition/declaration
//
// numword.cpp is numword class implementation/definition, implements interface

int main( int argc, char ** argv )
{
  bw::numword nw; // create object of numword class, bw:: because not
		  // using 'using namespace bw;'
  uint64_t n; // is in c stdard header file <cstdint>.  this is a 64bit
	      // unsigned integer, make int portable

  // print n value using the nw class
  //
  // eg output: n is 100073, one hundred thousand seventy-three
  n = 3; printf("n is %lld, %s\n", n, nw.words(n));
  n = 47; printf("n is %lld, %s\n", n, nw.words(n));
  n = 73; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1492; printf("n is %lld, %s\n", n, nw.words(n));
  n = 10012; printf("n is %lld, %s\n", n, nw.words(n));
  n = 100073; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1000000; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1000000001; printf("n is %lld, %s\n", n, nw.words(n));
  n = 123000000000; printf("n is %lld, %s\n", n, nw.words(n));
  n = 474142398123; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1474142398007; printf("n is %lld, %s\n", n, nw.words(n));
  n = 999000000000000; printf("n is %lld, %s\n", n, nw.words(n));
  n = 999999999999999999; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1000000000000000000; printf("n is %lld, %s\n", n, nw.words(n));
  
  
  // eg output is: 102 is one hundred two
  // eg output: print n = i = 0 to 200 and nw.words() prints i or n in words
  for( int i = 0; i < 201; ++i) {
    printf("%d is %s\n", i, nw.words(i));
  }
  
  return 0;
}
