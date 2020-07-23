// decltype.cpp by Bill Weinman <http://bw.org/>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Template fn:
//
// This allows the lhs and rhs arguments can be of different
// types!!!!!  ')->decltype(lhs + rhs)' is called a trailing return
// type, expression (lhs + rhs) is used to determine the type.
//
// decltype() is mostly used as a trailing return type in a template
// fn, as it is here.
// It allows you to operate on two different types of objects.
//
// So the deltype keyword allows type inference for template function
// return types.  It is essential for generic programming and is used
// a lot in the STL(Standard Template Library);
template <typename lhsT, typename rhsT>
auto tf(lhsT & lhs, rhsT & rhs)->decltype(lhs + rhs){
  return lhs + rhs;
}

int main( int argc, char ** argv ) {
  
    int i = 47;
    const char * cstr = "this is a c-string";
    string strobj("this is a string class string");
    
    auto x = string("this is a string class string");

    // decltype,  y is  also  a c++  string class,  type  of class  is
    // dependent  on the  type of  an  expression, (x)  in this  case,
    // whatever this type returned is the type of y.
    //
    decltype(x) y;

    // typeid() reports type of the object member.
    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of strobj is " << typeid(strobj).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;

    //auto z = tf(lhsT &lhs, rhsT &rhs);
    auto z = tf(cstr, strobj);
    cout << "z is "<< z << endl;
    cout << "type of z is " << typeid(z).name() << endl;
    
    return 0;
}



