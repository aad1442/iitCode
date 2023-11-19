#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main (void) {
  double x[101],y[101],df[101]; 
  int n = 100, i;
  double a = 0, b = 2*PI, h;
  h = (b - a) / n;
 
  x[0]= a;
  for( i=1; i<n; i++)  
    x[i] =x[i-1]+ h;
   x[n] = b;

  for(i=0;i<=n;i++)
    y[i]=sin(x[i]);

  df[0]=(y[0]-y[1])/(x[0]-x[1]);
  for(i=1;i<n;i++)
    df[i]=(y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
   df[n]=(y[n]-y[n-1])/(x[n]-x[n-1]);

    printf("\"x\",\"f(x)\",\"df(x)\"\n");
    for(i=0;i<=n;i++){
        printf("%lf,%lf,%lf\n",x[i],y[i],df[i]);
       
    }
     return 0;
}
