#include<stdio.h>
#include<math.h>
#define epsilon 10.0e-4
#define f(x) (((x)*(x)*(x))+(4*(x)*(x))-10)
//#define g(x) (pow(((10-(x*x*x))/4),0.5))
//#define g(x) ((10-(4*(x)*(x)))/((x)*(x)))
//#define g(x) ((10-((x)*(x)*(x)))/(4*(x)))
//#define g(x) (((x)*(x)*(x))+(4*(x)*(x))-10+x)
//#define g(x) ((10/((x)*(x)))-4)
#define g(x) (sqrt((10-((x)*(x)*(x)))/4))

//  double root(double num){
//     return sqrt(num);
// }
int main(){
    int iter=1;
     double x0=1.5;
     double x1;
     x1=(g(x0));
    printf("Iter   x0    x1    g(x0)    f(x1)\n");
     printf("%d  %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,g(x0),f(x1));
     while(fabs(f(x1))>epsilon){
     x0=x1;
     x1=g(x0);
     iter++;
     printf("%d  %.5lf %.5lf %.5lf %.5lf\n",iter,x0,x1,g(x0),f(x1));
     }

    printf("Root: %.5lf",x1);
}


