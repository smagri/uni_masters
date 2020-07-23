#include <stdio.h>

#define TRUE 1
#define FALSE 0

extern double fnInC(double value);

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
  double value;
  double retval;

  printf("hello, world\n\n");

  // ptrsAndRef
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


  // craysMacros
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
  for (i=0; i<10; i++){
    crayX[i] = i;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }
  fprintf(stderr, "reset crayX to all elements=99\n");
  for (i=0; i<10; i++){
    crayX[i] = 99;
    fprintf(stderr, "crayX[%i]=%f\n", i, crayX[i]);
  }

  fprintf(stderr, "\npopulate elements of crayX with a pointer & loop\n");
  i = 0;
  for (ptr=&crayX[0]; i<10; ptr++){
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
  for (ptr=crayX; i<10; ptr++){
    *ptr = i++;
    fprintf(stderr,
	    "ptr init=crayX, contents of pointer to crayX[%i]=%f\n",i,*ptr);
  }


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

  // Loops - Typecasting
  //
  // strrayX[] = "41012"; as for end of loop via NULL
  //
  fprintf(stderr, "\nLoops - Typecasting\n");

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


  // Switch Case - Const
  //
  // a switch statement tests wheather an expression matches one of a
  // number of integer values, and branches accordingly
  //
  // integers need to be in the case clause
  //
  fprintf(stderr, "\nSwitch Case - Const integers\n");


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
  

  // functions in c
  //
  // write a fn that accepts a double, 100.0, 1.0, 0.1
  fprintf(stderr, "\nCalling fnInC()\n");

  value = 100.0;
  retval = fnInC(value);
  if (retval == TRUE){
    fprintf(stderr, "case 2, returns bool=True\n");
  }
  else if (retval == FALSE){
    fprintf(stderr, "case 3, returns bool=False\n");
  }
  else{
    fprintf(stderr, "case 1, returns sqrValue=%f\n", retval);
  }

  value = 1.0;
  retval = fnInC(value);
  if (retval == TRUE){
    fprintf(stderr, "case 2, returns bool=True\n");
  }
  else if (retval == FALSE){
    fprintf(stderr, "case 3, returns bool=False\n");
  }
  else{
    fprintf(stderr, "case 1, returns sqrValue=%f\n", retval);
  }

  value = 0.1;
  retval = fnInC(value);
  if (retval == TRUE){
    fprintf(stderr, "case 2, returns bool=True\n");
  }
  else if (retval == FALSE){
    fprintf(stderr, "case 3, returns bool=False\n");
  }
  else{
    fprintf(stderr, "case 1, returns sqrValue=%f\n", retval);
  }
  
  
  return 0;
}


// functions in the c programming language
//
// to best protect the passed value pass a pointer to the function,
// that way the value is still there when the function returns
//
double fnInC(double value){

  double sqrValue;
  double cubeValue;

  fprintf(stderr, "\nvalue=%f\n", value);

  sqrValue = (value * value);
  fprintf(stderr, "sqrValue=%f\n", sqrValue);

  cubeValue = (value * value * value);
  fprintf(stderr, "cubeValue=%f\n", cubeValue);

  if ( (value > 0) && (value > sqrValue) ){
    return TRUE;
  }

  if( (value > 0) &&
      (value > sqrValue) &&
      (value > cubeValue) &&
      (value > (value+1)) ){
    
    return FALSE;
  }
  
  return sqrValue;
};
