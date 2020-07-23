#include<stdio.h>

int main(){

  double xcoords [5]; /*the x coordinates of our n points*/

  double ycoords [5]; /*the y coordinates of our n points*/

  double xin=0; /*the x whose f(x) we wish to compute*/

  double fx=0;/*the value of f(x)*/

  int i,j;

  double x0=0;

  double x1=0;

  printf("Enter the value of%f", x0);

  printf("Enter the value of%f", x1);

  for(i=0; i<5; i++){

    double Lg = 1;

    for(j=0; j<5; j++){

      if(i != j){
	Lg *= (xin-xcoords[j])/(xcoords[i]-xcoords[j]);
      }

    }

    fx= Lg*ycoords[i];

  }

  return 0;

}
