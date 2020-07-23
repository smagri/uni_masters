// working.cpp by Bill Weinman <http://bw.org/>

// enclude all contents of file cstdio.h into this file to pass to the compiler
//
// instructs preprocessor to search in implentation specific ares on
// the file system for cstdio.h
//
// note:
// #include <...> is used for system headers and
// #include "..." is used for local project headers, or those written by me.
//
#include <cstdio>

//#include "preproc.h"

// #if defined(MACRO) == #ifdef
// #if !defined(MACRO) == #ifndef

#include "includeA.h"
#include "includeB.h"



using namespace std;

// preprocessor(before the compiler) directive #define, can not have
// the # indented, define may be.
//
// #define SYMBOL replacementText, SYMBOL is not a variable
//#define ONE 1
//#define HELLO_STRING "Hello World"

// no space is allowed between ...MACRO(...
//#define MACRO(a, b) (a*b)
//#define MAX(a, b) (a > b ? a : b)


int main (int argc, char ** argv){

  // #define symbols are different to constants you can get it's
  // address
  //
  // is seen by debugger, seen in symbol table, symbolic constant is not
  // can get its address and with a symbolic constant you can not
  //
  // mostly use const... version in c++

  // backslash => contiue line, must be the last thing on the time, if
  // you put say a space after '\ ' it wont work???
  //
  // to make things more readable
  fprintf(stderr, "Hello World\n");
  
  return 0;
}