#include<stdio.h>
#include<math.h>
#define f(x) (((x)*(x))+1)
int main(){
    double a,b,sumX,sumI;
    a=0.0;
    b=2.0;
    int n=10;
    double h=(b-a)/n;
    double x[11],y[11];
    x[0]=a;
    x[n]=b;
    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
    } for(int i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    sumX=y[0]+y[n],sumI;
    for(int i=1;i<n;i++){
        sumI +=y[i];
    }
    printf("sumX %lf sumI %lf",sumX,sumI);
    printf("\n\"x\" \t\t\"f(x)\"\n");
    for(int i=0;i<=n;i++){
        printf("%lf\t %lf\n",x[i],y[i]);
    }
    printf("Integral value: %lf",(h*(sumX+(2*sumI)))/2);
}