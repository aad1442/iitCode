#include<bits/stdc++.h>
#define mx 100
using namespace std;

int n,W;

struct item{
    int weight;
    int value;
}items[100];

void knapSackInput(){
    ifstream myfile("0_1knapsack.txt");
    myfile>>n;
    for(int i=0; i<n; i++)
        myfile>>items[i].weight>>items[i].value;
    myfile>>W;

}

int dp[mx][mx];
void knapsack(int n, int W)
{
    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            if(!i || !w)
                dp[i][w]=0;
            else if(items[i-1].weight>w)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(items[i-1].value+dp[i-1][w-items[i-1].weight], dp[i-1][w]);
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=W; w++)
            cout<<dp[i][w]<<" ";
        cout<<endl;
    }
}

void print(int i, int w)
{
    if (i==0 || w==0)
        return;
    if (items[i-1].weight<=w && dp[i][w]==items[i-1].value+dp[i-1][w-items[i-1].weight])
    {
        print(i-1, w-items[i-1].weight);
        cout<<"item: "<<i<<endl;
    }
    else
    print(i-1, w);
}

int main()
{
    knapSackInput();
    
    
    knapsack(n, W);
    print(n,W);
    return 0;
}