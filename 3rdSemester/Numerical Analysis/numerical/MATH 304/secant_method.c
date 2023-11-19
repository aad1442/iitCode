#include<stdio.h>
#include<math.h>
#define epsilon 10.0e-6
#define f(x) ((x*x*x)+(4*x*x)-10)       //Xn
#define h(x) x1-(((x1-x0)/(f(x1)-f(x0)))*f(x1))

int main(){
    int iter=1;
     double x0=1.5;
     double x1=2.0;
     //double x2=x1-(((x1-x0)/(f(x1)-f(x0)))*f(x1));
     double x2=h(x1);
    printf("Iter   x0    x1    x2      f(x0)    f(x1)    f(x2)\n");
     printf("%d  %.5lf %.5lf %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,x2,f(x0),f(x1),f(x2));
     while(fabs(f(x2))>epsilon){
     x0=x1;
     x1=x2;
     x2 = h(x1);
     iter++;
     printf("%d  %.5lf %.5lf %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,x2,f(x0),f(x1),f(x2));
     }

    printf("Root: %lf",x2);
}

