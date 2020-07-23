// namespace.cpp by Bill Weinman <http://bw.org/>
#include <cstdio>
#include <string>

namespace bwstring {
    
    const std::string prefix = "(bwstring)";
    
    class string {
      std::string _s = ""; // in std namespace
      string (); // in bwstring namespace, this namespace
    public:
        string ( const std::string & s ) : _s( prefix + s) {};
        const char * c_str() { return _s.c_str(); }
        operator const std::string & () { return _s; };
    };
    
};	// namespace bwstring

std::string s1("This is a string");

// namespaces are typically defined in header files with the class
// definitions that use them
//
//
// sets default namespace to bwstring, thus
//
// bwstring::string s(s1); -> string s(s1)
// std::puts(s.c_str());
// 
//using namespace bwstring;
//
// using part of a namespace
//using bwstring::string;

int main( int argc, char ** argv ) {

  // produces string using our class member fns
  bwstring::string s(s1);
  std::puts(s.c_str());

  // Produces string from the std:: class member fns.  Thus here we
  // get the string s1 with bno bwstring prefix.
  std::string ss(s1);
  std::puts(ss.c_str());
  
  return 0;
}
