// recursive-factorial.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
using namespace std;

// n factorial computation is:
// n * (n-1) * (n-2) * (n-3) * (n-4) * ...1
// n factorial = (n-1) factorial
//
// a recursive function is a function that calls itself, however a
// loop is a more efficient way to do this.
//
// you can easily overrun your stack
//
unsigned long int factorial( unsigned long int n ) {
    if( n < 2 ) return 1;
    return factorial( n - 1 ) * n;
}

int main( int argc, char ** argv ) {
    unsigned long int n = 7;
    printf("Factorial of %ld is %ld\n", n, factorial(n));
    return 0;
}
