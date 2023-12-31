#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph;
const int maxV = 20;
int numV, numE;
int source,des;
vector<int>previous;

void printpath(int source, int sink){
    if(sink==-1)
        return;
    printpath(source,previous[sink]);
    cout<<" "<< sink<< " ";
}


bool bfs(int source, int dest, int v, vector<int>&previous)
{
    vector<bool>visited(v, false);
    queue<int>q;
    q.push(source);
    visited[source]=true;
    previous[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=1; i<=v; i++)
        {
            if(!visited[i] && graph[u][i]>0)
            {
                q.push(i);
                visited[i]= true;
                previous[i] = u;
            }
        }
    }
    return visited[dest];
}

int ford(int source, int dest, int v)
{
    previous.assign(v,0);
    int maxFlow=0;
    while(bfs(source, dest, v, previous))
    {
        int minCap=INT_MAX;
        for(int u=dest; u!=source; u=previous[u])
        minCap = min(minCap, graph[previous[u]][u]);

        for(int u=dest; u!=source; u=previous[u])
        {
            graph[previous[u]][u] -= minCap;
            graph[u][previous[u]] += minCap;
        }
        maxFlow+=minCap;
        printpath(source,des);
        cout<<"     "<<minCap<<endl;
    }
    return maxFlow;
}

void read() {
    ifstream myfile("networkFlowLabTask.txt");
    myfile >> numV;
    myfile >> source>>des>>numE;
    int u, v, w;
    graph.assign(numV+1, vector<int>(v+1,0));
    for (int i = 0; i < numE; i++) {
        myfile >> u >> v >> w;
        graph[u][v] = w;
        graph[v][v] = w;
    }
}

int main()
{
    read();
    cout<<"The Bandwith is: "<<endl<<ford(source, des, numV+1)<<endl;
    return 0;
}