#include <cstdio>


// Function declarations, as fn's if used before they are defined.
double fnOne(double value);
bool fnTwo(double value, double &sqrValue);
bool fnThree(double value,
	     double &sqrValue, double &cubeValue,
	     double &valuePlusOne);



int main(){

  double value = 10.0;
  double sqrValue, cubeValue, valuePlusOne;
  bool retval;
  int i;
  
  
  fprintf(stderr, "value is=%f\n", value);

  fprintf(stderr, "fnOne() returns value^2=%f\n", (fnOne(value))); //bit dodgy??


  fprintf(stderr, "fnTwo() returns:\n");
  retval = fnTwo(value, sqrValue);
  if(retval == true){
    fprintf(stderr, " value is >0\n");
  }
  else{
    fprintf(stderr, " value is not >0\n");
  }
  fprintf(stderr, " value^2=%f\n", sqrValue);


  fprintf(stderr, "fnThree() returns:\n");
  retval = fnThree(value, sqrValue, cubeValue, valuePlusOne);
  if(retval == true){
    fprintf(stderr, " value is >0\n");
  }
  else{
    fprintf(stderr, " value is not >0\n");
  }
  fprintf(stderr, " value^2=%f\n", sqrValue);
  fprintf(stderr, " value^3=%f\n", cubeValue);
  fprintf(stderr, " value plus one=%f\n", valuePlusOne);


  fprintf(stderr, "After 20 invocations fnThree() returns:\n");
  //
  //
  // do we want value=valuePlusOne for next invocation.
  //
  for(i=0; i<20; i++){
    retval = fnThree(value, sqrValue, cubeValue, valuePlusOne);
  }
  if(retval == true){
    fprintf(stderr, " value is >0\n");
  }
  else{
    fprintf(stderr, " value is not >0\n");
  }
  fprintf(stderr, " value^2=%f\n", sqrValue);
  fprintf(stderr, " value^3=%f\n", cubeValue);
  fprintf(stderr, " value plus one=%f\n", valuePlusOne);


  fprintf(stderr, "After 20 invocations fnThree() returns:\n");
  fprintf(stderr, "(where next value=valuePlusOne):\n");
  //
  //
  // do we want value=valuePlusOne for next invocation.
  //
  for(i=0; i<20; i++){
    retval = fnThree(value, sqrValue, cubeValue, valuePlusOne);
    value = valuePlusOne;
  }
  if(retval == true){
    fprintf(stderr, " value is >0\n");
  }
  else{
    fprintf(stderr, " value is not >0\n");
  }
  fprintf(stderr, " value^2=%f\n", sqrValue);
  fprintf(stderr, " value^3=%f\n", cubeValue);
  fprintf(stderr, " value plus one=%f\n", valuePlusOne);


  return 0;
}



// Function that accepts a double value as a parameter and:
double fnOne(double value){

  // returns a square value
    return (value * value);
};


// Function that accepts a double value as a parameter and:
//
// Use reference to sqrValue instead of c pointer ie double *sqrPtr;
bool fnTwo(double value, double &sqrValue){

  // Returns a bool value if double is > 0, and the square value
  // instead of the initial passed value.

  sqrValue = fnOne(value);

  if (value > 0){
    return true;
  }
  else{
    return false;
  }

};


// Function that accepts a double value as a parameter and:
//
// Use reference to sqrValue instead of c pointer ie double *sqrPtr;
bool fnThree(double value,
	     double &sqrValue, double &cubeValue,
	     double &valuePlusOne){

  // Returns a bool value if double is > 0, and the square value
  // instead of the initial passed value.

  sqrValue = fnOne(value);
  cubeValue = (sqrValue * value);

  valuePlusOne = ++value;
  

  if (value > 0){
    return true;
  }
  else{
    return false;
  }

};



