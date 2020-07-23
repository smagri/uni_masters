#include <stdio.h>

int main(){

  double x = 41012;
  double z = 1;
  double *ip;


  printf("hello, world\n\n");

  ip = &x; // pointer ip points to x
  fprintf(stderr, "value of x = %f\n", x);
  fprintf(stderr, "pointer ip points to x\n");
  fprintf(stderr, "value that ip is pointing too *ip=%f\n\n", *ip);

  // c programming
  // y = &x;
  // fprintf(stderr, "y references x\n");
  // fprintf(stderr,
  // 	  "value that of what y is pointing too(ie referencing) *y=%f\n\n", *y);
  //
  // c++ programming
  //
  // y is a reference for x
  // y must be initialised when its declared
  // When you use y it is the same as using x, as if it was variable x itself.
  //
  double &y = x;
  fprintf(stderr, "y references x, or double &y=x.\n");
  fprintf(stderr, "print value of what y is referencing to y=%f\n", y);
  fprintf(stderr, "print value of x=%f\n", x);
  
  ip = &z; // make pointer ip point to z
  y = z; // make y reference z
  fprintf(stderr, "\nvalue of z = %f\n", z);
  fprintf(stderr, "ip points to z\n");
  fprintf(stderr, "y references z, y=z???\n");
  fprintf(stderr, "print value ip is referencing = %f\n", *ip);
  fprintf(stderr, "print value y is referencing = %f\n", y);
    
    
  return 0;
}
