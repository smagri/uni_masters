// iostream-file.cpp by Bill Weinman <http://bw.org/>

// All of the  formatting works exactly the same with  the ofstream as
// it does  with cout.  So, the  iostream library  is very  useful for
// basic generalized  io, including  interfacing with the  console and
// writing to and reading files.

// For more control,  you may use the cstandard  library functions for
// reading and writing files.


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main( int argc, char ** argv ) {
    static int lineno = 0;
    static const char * filename = "test.txt";
    static const char * textstring = "This is the test file";
    
    // write a file
    cout << "write the file:" << endl;
    ofstream ofile(filename);
    ofile << ++lineno << " " << textstring << endl;
    ofile << ++lineno << " " << textstring << endl;
    ofile << ++lineno << " " << textstring << endl;
    ofile.close();
    
    // read a file
    static char buf[128];
    cout << "read the file:" << endl;
    ifstream infile(filename);
    while (infile.good()) {
      // if you can still read from the file (infile.good()), that is
      // you are not at the EOF.
        infile.getline(buf, sizeof(buf));
        cout << buf << endl;
    }
    infile.close();
    
    // delete file
    cout << "delete file." << endl;
    remove(filename);
    return 0;
}
