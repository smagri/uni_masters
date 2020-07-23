// exceptions.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string>
#include <exception>
using namespace std;

// exceptions used to report errors
//
// we want to use exceptions in constructors
//

static string unk = "unknown";
static string clone_prefix = "clone-";

// Exception class E inherits from exception class in the header
// <exception>
class E : public exception {
    const char * msg = nullptr;
    E(){};
public:
  // copy and paste these in your own projects
  //
  // overloads constructor allowing msg to be sent
    E(const char * s) throw() : msg(s) {}
  // overloads what() method which allows you to return a message
    const char * what() const throw() { return msg; }
};

class Animal {
    string _type;
    string _name;
    string _sound;
public:
    Animal();   // default constructor
    Animal(const string & type, const string & name, const string & sound);
    
    Animal(const Animal &); // copy constructor
    Animal & operator=(const Animal &); // copy operator
    ~Animal();  // destructor
    void print() const;
};

// -- implementation --
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");

    // if length of any input parameter/string is == 0, throw an exception
    if(type.length() == 0 || name.length() == 0 || sound.length() == 0) {
        throw E("Insufficient parameters");
    }
}

Animal::Animal(const Animal & a) {
    puts("copy constructor");
    _name = clone_prefix + a._name;
    _type = a._type;
    _sound = a._sound;
}

Animal::~Animal() {
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print () const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal & Animal::operator=(const Animal & o) {
    puts("assignment operator");
    if(this != &o) {
        _name = clone_prefix + o._name;
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
}

int main( int argc, char ** argv ) {
  // use try block to cath exceptions
  try {
    // part one, code your executing were exceptions may happen. if
    // exception occurs in constructor execution goes straigh to catch.
    // section
    Animal x("bear", "bill", "");
    x.print();
  } catch ( exception & e ) {
    // part two
    // where the exception object reports what the exception/error was
    // exception is called as last argument of x is a string of 0 size
    printf("Animal x: %s\n", e.what());
  }
    
    return 0;
}
