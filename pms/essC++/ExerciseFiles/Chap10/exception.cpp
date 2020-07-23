// exception.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <exception>
using namespace std;

// declare options to be thrown as exceptions
//
// The  exception class  has  a virtual  function  called "what"  that
// returns a c string. And this  function can be overloaded in derived
// classes to provide a description of your exception.
//
// Howto catch an exception and create your own exception class:

class E : public exception{
  const char *msg;
  // private default constructor so class can't be constructed without
  // the message string
  E(){}
public:
  // Constructor that allows you to pass a message.
  E(const char *s) throw() : msg(s){ }
  // overloads exception class version of this fn
  const char *what() const throw(){ return msg; }
};

// This system  is not easily  scalable.  So  you do the  following to
// make things simpler, comprising all your standard error conditions.
const E e_ouch("ouch!");
const E e_bad("bad code!");
const E e_worse("don't do that!");



// void broken(){
// throwing an exception form the std::exception class
//   cout << "this is a broken function" << endl;
//   throw exception();
  
// }

// throw my own exception, based on my E exception class
void broken(){

  cout << "this is a broken function" << endl;
  
  // throwing exception from E class, not the std::exception class;
  //throw E("this fn is brocken");
  //throw e_ouch;
  throw e_worse;
}



int main( int argc, char ** argv ) {

  cout << "let's have an emergency!" << endl;
//  broken();  // generates an exception
  // try loop
  // try{
  //   broken();  // generates an exception
  // } catch (exception &e){
  //   // catch an exception e.what() is using the std::exception class
  //   // so is not that helpfull.
  //   //
  //   // So you need to write your own exception class, which is easy to
  //   // do as you can derive from the std::exception class.
  //   //
  //   cout << "this can't be good: " << e.what() << endl;
  // }

  // using the E, derived from std exception, class.
  // try{
  //   broken();  // generates an exception of E class
  // } catch (E &e){
  //   // catch exception of E class
  //   // e.what() gets you the exception msg
  //   cout << "this can't be good: " << e.what() << endl;    
  // }

  // using the E, derived from std exception, class.
  try{
    broken();  // generates an exception of E class
  } catch (E &e){
    // catch exception of E class
    // e.what() gets you the exception msg
    cout << "this can't be good: " << e.what() << endl;    
  }
    
  return 0;
}
