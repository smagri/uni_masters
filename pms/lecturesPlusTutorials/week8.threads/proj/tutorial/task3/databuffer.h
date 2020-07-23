#ifndef DATABUFFER_H
#define DATABUFFER_H

#include <string>
#include <vector>
#include <mutex>

using namespace std;

// DataBuffer could be  a class or a  struct but we will  use a struct
// because we are allowing public access to the data and not providing
// any methods.
//
// ie  structs only  differ from  classes in  that they  don't contain
// methods/member functions.

struct DataBuffer{

  string name;
  vector<double> values;
  mutex buffer_mutex_;

};


#endif // DATABUFFER_H
