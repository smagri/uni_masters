#include <stdio.h>
#include <math.h>

#include <iostream>

#include "project1.h"


double squareroot (const double num){

  double retval = pow(num,0.5);
  
  if (retval >= 0){
    return retval;
  }
  else{
    std::cerr << "dbg: squreroot fn returns a value -1, or error\n";
    return -1;
  }
  
}

