// func-operator.cpp by Bill Weinman <http://bw.org/>
// updated for C++EssT 2014-10-24
#include <cstdio>
using namespace std;

class A {
    int a;
public:
    A ( const int &a ) : a(a) {}
    const int & value() const { return a; }
};
// operator here indicates operator overload function
//
// lhs, rhs is a typical representation of lhs operator rhs,ie lhs+rhs
// in this case
//
// use recerences for classes, constant refrences,when your passing
// them to fns.  classes are big and you don't want them on the stack,
// for obvious problems(ie stack overflow).
//
// 
int operator + (const A & lhs, const A & rhs ) {
    puts("operator + for class A");
    return lhs.value() + rhs.value();
}

int main( int argc, char ** argv ) {
    A a(7);
    A b(42);
    printf("add em up! %d\n", a + b);
    return 0;
}
