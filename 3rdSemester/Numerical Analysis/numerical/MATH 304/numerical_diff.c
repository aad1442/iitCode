#include<stdio.h>
#define f(x) (((x)*(x))+1)
int main(){
    double a,b;
    a=0.0;
    b=2.0;
    int n=10;
    double h=(a-b)/n;
    double x[11],y[11];
    x[0]=a;
    x[n]=b;
    for(int i=0;i<n;i++){
        x[i]=x[i-1]+h;
    } for(int i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    double Df[n+1];
    Df[0]=(y[1]-y[0])/(x[1]-x[0]);
    
    for(int i=1;i<n;i++){
        Df[i]=(y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
    }
    Df[n]=(y[n]-y[n-1])/(x[n]-x[n-1]);
    printf("x, f(x), df(x) ");
    for(int i=0;i<=n;i++){
        printf("%lf, %lf, %lf ",x[i],y[i],Df[i]);
        printf("\n");

    }
      
    }
    
