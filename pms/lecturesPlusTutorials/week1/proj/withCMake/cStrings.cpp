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
  int crayXsize, strrayXsize;
  double *ip;
  double *y;
  double *ptr;

 
  // c strings
  fprintf(stderr, "\nstrrayX=%s\n", strrayX);
  strrayXsize = (sizeof(strrayX) / sizeof(strrayX[0]));
  fprintf(stderr, "strrayXsize=%i\n", strrayXsize);

  // end of loop = (strrayXsize-1)
  /* fprintf(stderr, "end of loop = (strrayXsize-1)\n"); */
  /* i=0; */
  /* for (i=0; i<(strrayXsize-1); i++){ */
  /*   fprintf(stderr, "strrayX[%i]=%c\n", i, strrayX[i]); */
  /* } */

  // end of loop = while(nextChar != '\0')
  /* fprintf(stderr, "end of loop = while(nextChar != \'\\0\')\n"); */
  /* i=0; */
  /* nextChar = strrayX[i]; */
  /* while (nextChar != '\0'){ */
  /*   fprintf(stderr, "strrayX[%i]=%c\n", i, strrayX[i]); */
  /*   nextChar = strrayX[++i]; */
  /* } */

  // end of loop = while(nextChar != NULL)
  //
  // strrayX[i] is the integer, say '4', representing character 4 in the
  // machines character set, '4' is decimal integer 52.
  //
  // remember NULL is a pointer to a char, is char *, see strstr().
  fprintf(stderr, "end of loop = while(nextChar != NULL)\n");
  fprintf(stderr,
	  "nextChar is a ptr to a char, and NULL is a pointer to a char\n");

  i=0;
  nextChar = &strrayX[i]; // or, nextChar = =strray
  while (nextChar != NULL){
    fprintf(stderr, "strrayX[%i]=%c\n", i++, *nextChar++);
    if (*nextChar == 0){
      // *nextChar = '\0' == 0 = c string terminator found
      // nextChar = NULL is == &strrayX[0] = NULL
      nextChar = NULL;
    }
  }

  // strrayX[i] = NULL works for char[], or array of characters, as NULL
  // is a pointer to a char, not a pointer to a double.
  //&strrayX[1] = NULL;
  //fprintf(stderr, "strrayX[1]=%c\n", strrayX[1]);

  return 0;
}
