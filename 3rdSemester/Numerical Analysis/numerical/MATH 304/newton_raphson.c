#include<stdio.h>
#include<math.h>
#define epsilon 10.0e-6
#define f(x) ((x*x*x)+(4*x*x)-10)
#define df(x) ((3*x*x)+(8*x))
#define g(x) (x-(f(x)/df(x)))
int main(){
    int iter=1;
     double x0=1.5;
     double x1=g(x0);
    printf("Iter    x0    x1    f(x0)    df(x0)    f(x1)\n");
     printf("%d   %.5lf %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,f(x0),df(x0),f(x1));
     while(fabs(f(x1))>epsilon){
     x0=x1;
     x1=g(x0);
     iter++;
     printf("%d   %.5lf %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,f(x0),df(x0),f(x1));
     }

    printf("Root: %.5lf",x1);
}

