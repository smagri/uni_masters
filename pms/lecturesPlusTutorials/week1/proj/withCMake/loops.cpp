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

 
  // Loops - Typecasting
  //
  // strrayX[] = "41012"; as for end of loop via NULL
  //
  fprintf(stderr, "Loops - Typecasting\n");

  for (i=0; i<(strrayXsize-1); i++){
    fprintf(stderr, "strrayX[%i] cast to int is=%i\n", i, ((int) strrayX[i]));
    total += ((int) strrayX[i]);
  }
  fprintf(stderr, "total of strrayX[] integers in decimal is=%i\n", total);

  
  total = 0;
  fprintf(stderr, "count number of elements less than 2 with for loop\n");
  for (i=0; i<2; i++){
    fprintf(stderr, "strrayX[%i] cast to int is=%i\n", i, ((int) strrayX[i]));
    total += ((int) strrayX[i]);
  }
  fprintf(stderr,
	  "total of strrayX[] < than 2 integers in decimal is=%i\n", total);

  total = 0;
  i = 0;
  fprintf(stderr, "count number of elements less than 2 with while loop\n");
  while (i<2){
    total += ((int) strrayX[i++]);
  }
  fprintf(stderr,
	  "total of strrayX[] < than 2 integers in decimal is=%i\n", total);

  // Advances: use a for range loop??? what is this
  
  return 0;
}
