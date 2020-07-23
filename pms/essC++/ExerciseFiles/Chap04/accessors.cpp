// accessors.cpp by Bill Weinman <http://bw.org/>
// updated bw 2014-11-04
#include <cstdio>
#include <string>
using namespace std;

// c++ classes are based on c structures, except class member default to
// private and struct members default to public.

// Good practice to use struct when the struct will only have data
// members, use class when you need function members.


class A {
  // only in -std=c++...
  // int ia = 0;
  // string sb = "";
  // int ic = 0;
  int ia;
  string sb;
  int ic;
public:
    A ( const int a, const string & b, const int ic ) : ia(a), sb(b), ic(3) {};
    void seta ( const int a ) { ia = a; }
    void setb ( const string & b ) { sb = b; }
    void setc ( const int c ) { ic = c; }
    int geta () const { return ia; }
    const string & getb () const { return sb; }
    const char * getb_cstr () const { return sb.c_str(); }
    int getc () const { return ic; }
};

int main( int argc, char ** argv ) {
    A a(1, "two", 3);
    printf("ia is %d, sb is %s, ic is %d\n", a.geta(), a.getb_cstr(), a.getc());
    return 0;
}