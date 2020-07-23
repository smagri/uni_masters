// implicit-explicit.cpp by Bill Weinman <http://bw.org/>
// bw updated 2014-11-02
#include <cstdio>
using namespace std;

const size_t _maxsize = 1024;

class strsize {
    size_t _size = 0;
public:
  // If I put explicit type => no implicit conversions allowed.
  // Always best to use the explicit constructor.
  //
  // explicit strsize(const int);     // constructor: size from int
  // explicit strsize(const char *);  // constructor: size from c-string
  //
  // These implcit conversions don't work with explicit type.
  // strsize s = "x";
  // printf("size is %ld\n", s.size());
  // func("x");
  strsize(const int);     // constructor: size from int
  strsize(const char *);  // constructor: size from c-string
  size_t size() const;
};

strsize::strsize(const int n) {
  // _size = n
    puts("constructor: size from int");
    _size = (n <= _maxsize) ? n : 0;
}

strsize::strsize(const char * s) {
  // sets _size = size of string s
    puts("constructor: size from c-string");
    for(size_t i = 0; i < _maxsize; i++) {
        if(s[i] == 0) {
            _size = i;
            return;
        }
    }
    _size = 0;
}

size_t strsize::size() const {
  // getter fn, gets current value of _size
    return _size;
}

using namespace std;


void func(const strsize & s) {
    printf("size is %ld\n", s.size());
}



int main( int argc, char ** argv ) {

  // char = 120 decimal
  //
  // Also, an implicit conversion when assigning an object a value, value
  // gets promoted to one of the default constructors.
  //
  //  strsize s = 'x';
  //  func('x');
  //
  // These implcit conversions don't work with explicit type.
  // strsize s = "x";
  // printf("size is %ld\n", s.size());
  // func("x");

  // Best to use explicit constructors, this always works properly.
  //
  // So forget about implicit conversions!!! i think.
  strsize s("x");
  printf("size is %ld\n", s.size());
  func(strsize("x"));

  strsize si(7);
  printf("size is %ld\n", si.size());
  func(strsize(5));
  
  return 0;
}

