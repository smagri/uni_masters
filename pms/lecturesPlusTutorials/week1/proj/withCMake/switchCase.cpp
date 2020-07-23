#include <stdio.h>

int main(){

  double x = 41012;
  double z = 1;
  double crayX[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // no need to specify size on initialisation
  //
  // in c strings are terminated by a NULL or end of string = 0 = '\0'
  // initialise using initialiser list
  char strrayX[] = {'4', '1', '0', '1', '2', '\0'};
  // OR
  // char strrayX[] = "41012";

  //char nextChar;
  char *nextChar;
  int i;
  int total = 0;
  int crayXsize, strrayXsize;
  double *ip;
  double *y;
  double *ptr;

 
  // Switch Case - Const
  //
  // a switch statement tests wheather an expression matches one of a
  // number of integer values, and branches accordingly
  //
  // integers need to be in the case clause
  //
  fprintf(stderr, "Switch Case - Const integers\n");

  fprintf(stderr, "\nstrrayX=%s\n", strrayX);
  strrayXsize = (sizeof(strrayX) / sizeof(strrayX[0]));
  fprintf(stderr, "strrayXsize=%i\n", strrayXsize);
  

  for (i=0; i<(strrayXsize-1); i++){

    switch (strrayX[i]){
      case '0':
	fprintf(stderr, "'0' is zero\n");
	break;
      case '1':
	fprintf(stderr, "'1' is one\n");
	break;
      case '2':
	fprintf(stderr, "'2' is two\n");
	break;
      case '4':
	fprintf(stderr, "'4' is four\n");
	break;
      default:
	fprintf(stderr, "invalid, this character not tested for\n");
	break;
    }
    
  }
  
  
  return 0;
}
