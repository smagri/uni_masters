#include <stdio.h>

int main(){

  double x = 41012;
  double z = 1;
  double *ip;
  double *y;

  printf("hello, world\n\n");

  ip = &x;
  fprintf(stderr, "value of x = %f\n", x);
  fprintf(stderr, "pointer ip points to x\n");
  fprintf(stderr, "value that ip is pointing too *ip=%f\n\n", *ip);
    
  y = &x;
  fprintf(stderr, "y references x\n");
  fprintf(stderr,
	  "value that of what y is pointing too(ie referencing) *y=%f\n\n", *y);

  ip = &z;
  y = &z;
  fprintf(stderr, "value of z = %f\n", z);
  fprintf(stderr, "ip pointer points to z\n");
  fprintf(stderr, "y references z\n");
  fprintf(stderr, "print value ip is referencing = %f\n", *ip);
  fprintf(stderr, "print value y is referencing = %f\n", *y);
    
    
  return 0;
}
