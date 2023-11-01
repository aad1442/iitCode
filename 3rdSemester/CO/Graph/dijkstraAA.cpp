#include <iostream>
#include <map>
#include <fstream>
#include<climits>
using namespace std;

#define MAX 20

map<char, int> edge;
int numV, numE;
int graph[MAX][MAX];
int d[MAX],p[MAX];
bool set[MAX];

void read() {
    ifstream myfile("d_graph.txt");
    myfile >> numV >> numE;
    char u, v;
    int w;
    int n = 0;
    while (!myfile.eof()) {
        myfile >> u >> v >> w;
        if (edge[u] == 0) {
            edge[u] = ++n;
        }
        if (edge[v] == 0) {
            edge[v] = ++n;
        }
        graph[edge[u]][edge[v]] = w;
    }
    myfile.close();
}

void printGraph() {
    map<char, int>::iterator i = edge.begin();
    while (i != edge.end()) {
        cout << i->first << "  " << i->second << endl;
        i++;
    }

    cout<<" done !"<<endl;
    for (int i = 1; i <= numV; i++) {
        for (int j = 1; j <= numV; j++) {
            cout << graph[i][j] << "   ";
        }
        cout << endl;
    }

    for(int i=1;i<=numV;i++){
        cout<< d[i] <<endl;
    }
}

void initializeSingleSource(int numV , int s){
    for(int i=1;i<=numV;i++){
        d[i]=INT_MAX;
        p[i]=-1;
        set[i]=false;
    }
    d[s]=0;
}
int extractMin(){
    int min=INT_MAX,minIndex = 0;
    for(int i=1;i<= numV;i++){
        if(d[i]<min && !set[i]){
            min = d[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void relax(int u, int v, int w){
    if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        p[v]=u;
    }
}

void Dijkstra(int g[][MAX],int dis[],int source){
 initializeSingleSource(numV,source);
 int u;
 while ((u=extractMin())!=0)
 {
    set[u]=true;
    for(int v=1;v<=numV;v++){
        if(graph[u][v]&&set[v]==false){
            relax(u,v,graph[u][v]);
        }
        
    }
 }
 
}

int main() {
    read();
    printGraph();
    Dijkstra(graph,d,1);
    printGraph();

    return 0;
}


