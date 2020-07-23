// new-delete.cpp by Bill Weinman <http://bw.org/>
// updated 2014-10-08 bw
#include <cstdio>
#include <new>
using namespace std;

// till now we have been using dynamically allocated objects, but
// sometimes you want the object to be persistant beyond a fn or block


class A {
    int _a = 0;
    int _b = 0;
    int _c = 0;
public:
    A( int i = 0 );
    ~A();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
};

A::A( int i ) : _a(i), _b(i + 1), _c(i + 2) {
    puts("A constructor called");
}

A::~A() {
    puts("A destructor called");
}

int main( int argc, char ** argv ) {
  //puts("allocating space for one A object");
  puts("allocating space for three A objects");

    // new returns a pointer to object A, a is that pointer
    // constructor of A is called to create object A
    //
    // If your not using exceptions for error reporting then you need
    // the nothrow option with new, so null pointer is returned
    //
    //A * a = new (nothrow);
    // OR
    //A * a = new (nothrow) A(5);
    //
    // OR for array of objects, but requires delete []; instead of delete; .
    //
    A * a = new (nothrow) A[3];
    
    if(a == nullptr) {
        puts("new A failed");
        return 1;
    }
    printf("a: %d, %d, %d\n", a->a(), a->b(), a->c());
    
    //delete a;
    delete []a; // otherwise your program with leak memory
    // object and it space is delete, space goes back to heap/static memory
    puts("A object has been deleted");
    
    return 0;
}
