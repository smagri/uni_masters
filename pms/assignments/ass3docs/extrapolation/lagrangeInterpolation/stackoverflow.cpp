#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

const double pi=3.14159265358979323846264338327950288;

// my function
double f(double x){

  return (cos(pi*x));

}


//function to compute lagrange polynomial
double lagrange_polynomial(int N,double *x){
  //N = degree of polynomial

  double z,y;
  double *L_coeff=new double [0];//L_coefficients of every Lagrange
				 //L_coefficient
  double *d;//hold the polynomials values for every Lagrange coefficient
  int k,i;
  //computations for finding lagrange polynomial
  //double sum=0;

  for (k=0;k<N+1;k++){
    for ( i=0;i<N+1;i++){
      if (i==0) continue;
      d[0]=(z-x[i])/(x[k]-x[i]);//initialization
      if (i==k) L_coeff[k]=1.0;
      else if (i!=k){
	L_coeff[k]*=d[i];
      }
    }

    cout <<"\nL("<<k<<") = "<<d[i]<<"\t\t\tf(x)= "<<f(x[k])<<endl;
  }

}


int main(){

  double deg,result;
  double *x;


  cout <<"Give the degree of the polynomial :"<<endl;
  cin >>deg;

  for (int i=0;i<deg+1;i++){
    cout <<"\nGive the points of interpolation : "<<endl;
    cin >> x[i];
  }

  cout <<"\nThe Lagrange L_coefficients are: "<<endl;
  result=lagrange_polynomial(deg,x);

  return 0;
}
