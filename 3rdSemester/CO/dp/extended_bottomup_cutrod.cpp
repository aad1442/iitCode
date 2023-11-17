#include<bits/stdc++.h>
using namespace std;
#define mx 100
int r[mx],s[mx];
int cost;

int bottom_up_cut_rod(int p[],int n){
    // int r[n+1],s[n+1];
    r[0]=0;

    for(int j=1;j<=n;j++){//j indicates the rod length
        int q=-INT_MAX;
        for(int i=1;i<=j;i++){
           if(q<p[i]+r[j-i]){
            q=p[i]+r[j-i];
            s[j]=i;
           }
        }
        r[j]=q;//r[j] array indicates j length er rod er jonno max revenue
    }

    return r[n];
}

void print_cut_rod_solution(int p[],int n){
    while(n>0){
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    cout<<endl;
}

int main(){

    // int size=sizeof(p)/sizeof(p[0]);

    // int p[]={0,1,5,8,9,10,17,17,20,24,30};
    int p[]={0,1,5,8,9,10,12,17,19};
    cost=1;
    int n;
    cout<<"Enter rod length:";
    cin>>n;

    int max_revenue=bottom_up_cut_rod(p,n);
    if(cost>0){
        max_revenue+=cost;
    }
    cout<<"\nMax revenue is:"<<max_revenue<<endl;
    
    print_cut_rod_solution(p,n);


}