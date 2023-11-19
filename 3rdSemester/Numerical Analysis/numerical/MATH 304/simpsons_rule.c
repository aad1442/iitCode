#include<stdio.h>
#include<math.h>
#define f(x) (((x)*(x))+1)
double a,b,sumX,sumO,sumE;
void simpson(int n){
  if((n%2)!=0){
        n=n+1;
    }
    double h=(b-a)/n;
    double x[11],y[11];
    x[0]=a;
    x[n]=b;
    for(int i=1;i<n;i++){
        x[i]=x[i-1]+h;
    } for(int i=0;i<=n;i++){
        y[i]=f(x[i]);
    }
    sumX=y[0]+y[n];
    for(int i=1;i<n;i++){
        if((i%2)==0)
        sumE +=y[i];
        else sumO +=y[i];
    }
    //  for(int i=2;i<=n-2;i++){
    //     sumE +=y[i];
    // }
    printf("sumX %lf sumO %lf sumE %lf",sumX,sumO,sumE);
    printf("\n\"x\" \t\t\"f(x)\"\n");
    for(int i=0;i<=n;i++){
        printf("%lf\t %lf\n",x[i],y[i]);
    }
    printf("Integral value: %lf",h*(sumX+(4*sumO)+(2*sumE))/3);
}


int main(){
   
    a=0.0;
    b=2.0;
    int n;
    n=9;
    simpson(n);
    
}