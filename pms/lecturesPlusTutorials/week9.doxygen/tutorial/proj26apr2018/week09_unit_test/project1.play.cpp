#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include  <iostream>
#include "project1.h"


//double squareroot (const double num){
double squareroot (const double num){

  double retval = pow(num,0.5);

  // if (retval < 0.0){

  //   // no wrks:
  //   //return -nan;
  //   //return nan;
  //   //return NaN;
  //   //return NAN;
  //   //return -NAN;
    
  //   // wrks:
  //   std::cerr << "Error: Negative Input\n";
  //   //return -1;
  //   //exit(-1);
  //   return NaN;

  //   //perror("squareroot");
  // }
  // else{
  //   return retval; 
  // }

  if (retval == (!0)){
    return -1;
  }
  else
    return 1;
  
};

