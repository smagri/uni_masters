// func.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>

#include "func.h" // most common way to declare a fn

using namespace std;

// functions need to be declared before they are used

//void func(); // fn declaration or use this in func.h


int main( int argc, char ** argv ){

  int x = 42;
  puts("this is main()");

  fprintf(stderr, "before func(x) x=%d\n", x);

  // no pass by value(default in c and c++), pass by reference instead
  func(x);
  
  // value of x changes as x = int &i, ie i is a reference to x, so
  // effectively i becomes x
  fprintf(stderr, "after funx(x) value is x=%d\n", x);
  
  return 0;
}


void func(int &i){

  // pass by reference in c++
  i = 73;
  puts("this is func()");

  fprintf(stderr, "in func (int &i) i=%d\n", i);

  
}

