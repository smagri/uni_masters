// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string>
using namespace std;

// Derived class member fn overrides derived class member gn

// Default destructors get called when no destructors are defined.

// Overloading methods  or member  functions in  derived classes  is a
// fundamental  part of  object  oriented  programming and  especially
// polymorphism. This gives you a lot  of power and flexibility in how
// you design your class

// Polymorphisim is running the same fn name in different classes.  So
// which fn gets called is decided at run time, that is it depens on
// the object you are accessing.

// Base class
class Animal {
  string _name;
  string _type;
  string _sound;
  // private constructor prevents construction of base class
  Animal(){};
protected:
  // protected constructor for use by derived classes
  Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}
public:
  // Whenever you declare anything virtual you need to provide a
  // virtual destructor.
  virtual ~Animal(){};
  
  // virtual => that the for base class member fn speak().
  virtual void speak() const;
  const string & name() const { return _name; }
  const string & type() const { return _type; }
  const string & sound() const { return _sound; }
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int walked;
public:
    Dog( string n ) : Animal(n, "dog", "woof"), walked(0) {};
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
class Cat : public Animal {
    int petted;
public:
  Cat( string n ) : Animal(n, "cat", "meow"), petted(0) {};
  int pet() { return ++petted; }
  // overloads the speak() member fn in Animal class.
  void speak() const;
};

void Cat::speak() const{
  printf("purr\n");
}

// Pig class - derived from Animal
class Pig : public Animal {
    int fed;
public:
    Pig( string n) : Animal(n, "pig", "oink"), fed(0) {};
    int feed() { return ++fed; }
};

int main( int argc, char ** argv ) {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();

    // This will now say 'purr' only as the speak() member fn of Cat
    // class gets executed.  As Cat class member fn speak() overloads
    // Animal class member fn speak().  Cat is derived from Animal
    // class.
    c.speak();
    p.speak();
    
    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the pig has been fed %d times\n", p.feed());

    //
    //
    Animal *ap[] = {&d, &c, &p};
    for (Animal *a : ap){
      // It choses base class version of speak() member fn over
      // derived class speak() as pointer a is typed as Animal base
      // class.
      //
      // However, to get it to use the derived class overloaded fn
      // speak() you can declare the base version as virtual, so done
      // so in the code.
      //
      // So now a->speak() where a-> points to c will just output
      // 'purr' as thats what the c.speak() member fn does.
      //
      // The virtual qualifier tells the compiler that the function
      // may be overloaded, and to prefer the derived version rather
      // than the base version.  This allows the pointer to be
      // polymorphic.
      //
      // So now a->speak() will execute the derived class overloaded
      // fn speak(), not the base class speak().
      //
      // So this ensures also that the default destructors in the
      // derived classes of Dog Cat and Pig are executed, not the
      // destructor of the base class Animal.
      a->speak();
    }
}
