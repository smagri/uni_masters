// string.cpp by Bill Weinman <http://bw.org/>

// The STL  String class is  a special type of  container specifically
// designed to  operate with sequences  of characters. It's  very much
// like a vector but with a additional string-related functions

// Demostrate here different methods, or member functions of the string class.
//
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char ** argv ) {
  string s1 = "This is a string"; // uses the copy constructor
  string::iterator it;
    
  // size & length are ==
  cout << "size is same as length: " << s1.size() << endl;
  cout << "size is same as length: " << s1.length() << endl;
  
  // + for concatenation
  cout << "concatenated strings: ";
  string s2 = "this is also a string";
  cout << s1 + ":" + s2 << endl;
  
  // compare
  //
  // use the conditional operator, answer is no here.
  cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
  cout << "copy-assign s2 = s1" << endl;
  s2 = s1;
  cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
  cout << "is s1 > \"other string\"? " << (s1 > "other string" ? "yes" : "no") << endl;
  cout << "is s1 < \"other string\"? " << (s1 < "other string" ? "yes" : "no") << endl;
  cout << "is \"other string\"? > s1  " << ("other string" > s1 ? "yes" : "no") << endl;
  cout << "is \"other string\" < s1? " << ("other string" < s1 ? "yes" : "no") << endl;
    
  // iteration
  //
  // using a range-based for loop, ie container s1 and holder is c.
  // The container here is a string of characters here.
  cout << "each character: ";
  for( char c : s1 ) {
    cout << c << " ";
  }
  cout << endl;
  
  // insert & erase with an iterator
  //
  // array index starts from 0 and begin+5 is the sixth element, thus
  // array[5]
  //
  it = s1.begin() + 5;
  s1.insert(it, 'X');
  cout << "after insert: " << s1 << endl;
  
  it = s1.begin() + 5;
  s1.erase(it);
  cout << "after erase: " << s1 << endl;
  
  // replace
  s1.replace(5, 2, "ain't");
  cout << "after replace: " << s1 << endl;
  
  // substr
  //
  // extract five charactres starting from the fifth position
  cout << "substr: " << s1.substr(5, 5) << endl;
  
  // find
  size_t pos = s1.find("s");
  cout << "find first \"s\" in s1 (pos): " << pos << endl;
  
  // rfind
  pos = s1.rfind("s");
  cout << "find last \"s\" in s1 (pos): " << pos << endl;
    
  return 0;
}
