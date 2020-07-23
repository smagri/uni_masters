// rational.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <iostream>
using namespace std;


// To overload operators in C++:
// * One is with member functions as part of a class definition
// * and the other is a separate nonmember functions discussed in another movie.
//
class Rational {
  int _n = 0; // numerator
  int _d = 1; // denominator
public:
  // Default denominator is 1, default numerator is 0, that is if you
  // do not specify the argument values/parameters to this fn.
  Rational ( int numerator = 0, int denominator = 1 ) : _n(numerator), _d(denominator) {};
  // copy constructor: takes a reference to a Rational object and
  // copies it into the private member data of this Rational class.
  Rational ( const Rational & rhs ) : _n(rhs._n), _d(rhs._d) {};
  ~Rational ();
  // getters(), are constant safe, ie they don't modify anything
  inline int numerator() const { return _n; };
  inline int denominator() const { return _d; };
  // operator overloads
  //
  // only assignment operator is not constant safe, as it needs to
  // change the member data.
  //
  // Constant safe means:
  // for arguments/perameters: parameters aren't modifiable.
  // for fns: function/method does not modfiy its perameters.
  //
  Rational & operator = ( const Rational & ); // assignment operator
  //
  // four arithmetic operators:
  Rational operator + ( const Rational & ) const;
  Rational operator - ( const Rational & ) const;
  Rational operator * ( const Rational & ) const;
  Rational operator / ( const Rational & ) const;
  
  // operator overload for the conversion operator
  // returns operatpr
  // cast operator is std::string
  operator std::string () const;
  
};

Rational & Rational::operator = ( const Rational & rhs ) {
  // assignent operator
  if( this != &rhs ) {
    // current object is !== rhs Rational object, set the new
    // numerator and denominator values to that of rhs object.
    _n = rhs.numerator();
    _d = rhs.denominator();
  }
  
  // Current object is == rhs Rational object so just return ourself.
  //
  // And we need to return a reference so we need to return and
  // address.  'this' is a pointer to an object, so *this is an
  // address/reference/pointer value, ie reference to object itself
  // instead of a reference to the pointer.
  return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
  
  // formula defines how you add two fractions:
  // with (_n * rhs._d) + (_d * rhs._n) as new numerator = _n
  // with (_d * rhs._d) as new denominator = _d
  // uses two parameter Rational constructor above.
  return Rational( (_n * rhs._d) + (_d * rhs._n), _d * rhs._d );
}

Rational Rational::operator - ( const Rational & rhs ) const {

  // formula defines how you subtract two fractions:
  // uses two parameter Rational constructor above.
  return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
  // formula defines how you multiply two fractions:
  // with (_n * rhs._n) as new numerator = _n
  // and (_d * rhs._d) as new denominator = _d
  // uses two parameter Rational constructor above.
  return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator / ( const Rational & rhs ) const {
    return Rational(_n * rhs._d, _d * rhs._n);
}

Rational::operator std::string () const{
  const static int maxstring = 64;
  char s[maxstring];
  //snprintf(char *, size_t, const char*, ...);
  // like printf but puts output to a string
  // n = can use a maximum size
  // s = _n/_d
  snprintf(s, maxstring, "%d/%d", _n, _d);

  // c++ string object, temporary object and initalising it with s
  // use to convert your class to any type, like a cast for a class
  return std::string(s);
}
  

Rational::~Rational() {
  fprintf(stderr, "dtor: %d/%d\n", _n, _d);
    _n = 0; _d = 1;
}

// useful for std::cout
//
// needs the <
std::ostream & operator << (std::ostream & o, const Rational & r) {
  // not sure what is happening here:
  //
  // non-member fn overload:
  // needs #include <iostream> above for ostream use
  // returns reference to ostream object o
  // we overload the << operator to do this
  // lhs = cout/ostream object o, rhs = reference to Rational object
  // returns the ostream object o
  //
  // for an object of type Rational, r, print out 'numerator /
  // denominator' in this form.
  //
  return o << r.numerator() << '/' << r.denominator();
}

int main( int argc, char ** argv ) {

  // Create a number of objects, constucted in different ways:
  //
  // 7/1, implicit type conversion-ignore!!!, so uses first constructor.
  Rational a = 7;
  cout << "a is: " << a << endl;
  Rational b(5, 3);		// 5/3
  cout << "b is: " << b << endl;
  Rational c = b;		// copy constructor
  cout << "c is: " << c << endl;
  Rational d;			// default constructor
  cout << "d is: " << d << endl;
  d = c;			// assignment operator
  cout << "d is: " << d << endl;
  Rational & e = d;		// reference
  // assignment to self!, not a valid thing to do, see operator = code
  // for explination. d=e; uses the assignment operator overload fn.
  //
  // so basically d and e are the same address so no new values for
  // numerator and denomenator are calculated, hene d and e still have
  // the same old values
  d = e;			
  cout << "e is: " << e << endl;

  // Arithmatic on objects using normal operators.  What happens is
  // dictated by the class in the operator overload methods, ie
  // Rational::operator xx methods. ie operator keyword=operator, xx
  // is the operator sign.
  //
  // dtor: is called at the end of all the operator fns as the values
  // generated in the operator fn's return a temporary object, which
  // doesn't exist outside the fn.
  //
  // Then each of the four objects a, b, c, d are destroyed.
  //
  // also see: ostream overloading to determine how the output is
  // printed here.
  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;

  // chain assignments, expected of assinment operator, =,  in c++:
  // assignment operator of a returns a reference to itself...etc
  d = c = b = a;
  fprintf(stderr, "a is %d/%d\n", a.numerator(), a.denominator());
  fprintf(stderr, "b is %d/%d\n", b.numerator(), b.denominator());
  fprintf(stderr, "c is %d/%d\n", c.numerator(), c.denominator());
  fprintf(stderr, "d is %d/%d\n", d.numerator(), d.denominator());

  // what if we want a string from our fraction
  //
  string s = "Rational as a string";

  // += is operator overload in the string class, b=5/3 fractn
  // c++ string s as it's operand
  // operator overload is a fn
  //
  // b rational object is converted to a string using the += overload
  // operator, thus casting b to a string, can do this for converting
  // any class to any type
  s += b;
  
  cout << s << endl;
  
  return 0;	
}
