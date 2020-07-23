// working.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

// A  pair  is  a  simple  fixed container  for  holding  two  related
// values. While it's not very complicated  and it's not often used on
// it's own, it is used by a number of other classes in the STL.



int main( int argc, char ** argv ){

  // a very simple template class:
  // with ints
  pair<int, int> p = {5, 47};
  cout << "first is " << p.first << ", second is " << p.second << endl;

  // with strings
  pair<int, string> pStr = {5, "this is a string"};
  cout << "first is " << pStr.first << ", second is " << pStr.second << endl;

  return 0;
}
