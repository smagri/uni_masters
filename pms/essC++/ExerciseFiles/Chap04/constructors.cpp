// constructors.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

// -- interface --
class Animal {
    string _type = "";
    string _name = "";
    string _sound = "";
  // If you put the default constructor here, => it is private, => it
  // is not usable or valid at all so can't create objs with it.
public:
  // default constructor, which is different to the implicit default
  // constructors.
  //
  // default constructor have no arguments/parameters.
  //
    Animal();

  // Another constructor, one with arguments/parameters.
    Animal(const string & type, const string & name, const string & sound);
    
    Animal(const Animal &); // copy constructor
    Animal & operator=(const Animal &); // copy operator
    ~Animal();  // destructor
    void print() const;
};

// -- implementation --
//
// Where _type(unk), _name(unk), _sound(unk) is an initialisation list where:
// _type(unk) is member data '_type = unk' value, note string unk="unkown".
Animal::Animal() : _type(unk), _name(unk), _sound(unk) {
    puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
    puts("constructor with arguments");
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

// rule of  threes, if you are  going to overload any  of the implicit
// copy  operator, copy  destructor,  copy  constructor, overload  all
// three is a good idea.


int main( int argc, char ** argv ) {

  // default constructor, creates an object a.
    Animal a;
    a.print();

    // constructor creates an object b.
    const Animal b("goat", "bob", "baah");
    b.print();

    // calls the copy _constructor_ as using the copy operator to
    // create an object, creates an object c.
    const Animal c = b;
    c.print();

    // copy _operator_, note no object created => no constructor called,
    // is assignment operator
    a = c;
    a.print();
    
    return 0;  // Here all the destructors, for all the objects get
	       // called.  In this case all of them a,b,c have the
	       // same destructor ~Animal();
}
