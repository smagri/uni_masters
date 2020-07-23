// func.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string> // c++ library provides the string class

//void func(string & fs);

using namespace std;

// functions need to be declared before they are used

//void func(); // fn declaration or use this in func.h

void func(const string & fs){
  
  // Pass by reference in c++, using a string, this is why references
  // in c++ were created, that is to pass big objects like strings
  // between functions.  So we don't overflow the stack an cause a
  // security vunrability an crash your code.
  //
  // const string means that fs is readonly or immutale string
  // within this function, that is this funcion can't alter value of
  // fs.
  puts("this is func()");

  fprintf(stderr, "in func(string &fs) s=%s\n", fs.c_str());
}


int main( int argc, char ** argv ){

  string s = "im a string";
  puts("this is main()");

  //fprintf(stderr, "before func(s) s=%s\n", s.c_str());

  // no pass by value(default in c and c++), pass by reference instead
  func(s);
  
  // value of x changes as x = int &i, ie i is a reference to x, so
  // effectively i becomes x
  fprintf(stderr, "after funx(s) value is =%s\n", s.c_str());
  
  return 0;
}
