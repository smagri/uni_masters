#include <stdio.h>

int main(){

  double x = 41012;
  double z = 1;
  double crayX[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i;
  int crayXsize;
  double *ip;
  double *y;
  double *ptr;

  
  // C arrays - MACRO
  //
  crayXsize = ( sizeof(crayX) / sizeof(crayX[0]) );
  fprintf(stderr, "\nsize of crayX=%i\n", crayXsize);
    
    
  fprintf(stderr, "\npopulate elements of crayX on array creation\n");
  for (i=0; i<10; i++){
    fprintf(stderr, "crayX[i]=%f\n", crayX[i]);
  }
  fprintf(stderr, "reset crayX to all elements=99\n");
  for (i=0; i<10; i++){
    crayX[i] = 99;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }

  fprintf(stderr, "\npopulate elements of crayX with a loop\n");
  for (i=0; i<crayXsize; i++){
    crayX[i] = i;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }
  fprintf(stderr, "reset crayX to all elements=99\n");
  for (i=0; i<crayXsize; i++){
    crayX[i] = 99;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }

  fprintf(stderr, "\npopulate elements of crayX with a pointer & loop\n");
  i = 0;
  for (ptr=&crayX[0]; i<crayXsize; ptr++){
    *ptr = i++;
    fprintf(stderr,
	    "ptr init=&crayX[0], contents of pointer to crayX[%i]=%f\n",i,*ptr);
  }
  fprintf(stderr, "reset crayX to all elements=99\n");
  for (i=0; i<10; i++){
    crayX[i] = 99;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }
  i = 0;
  for (ptr=crayX; i<crayXsize; ptr++){
    *ptr = i++;
    fprintf(stderr,
	    "ptr init=crayX, contents of pointer to crayX[%i]=%f\n",i,*ptr);
  }
  
  return 0;
}
