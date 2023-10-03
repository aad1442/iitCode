#include<iostream>
#include<fstream>
#include<map>
#include<climits>
using namespace std;
#define max 20
int vertices, edges;
int graph[max][max]={0};
map<char, int> mp;
void read(){
    ifstream file("graph.txt");
    if(!file.is_open()){
        cerr<< "Can't open the file. "<< endl;
        exit(1);
    }
    file >> vertices >> edges;
    for(int i=0;i<vertices;i++){
        mp['a'+i]=0+i;
    }
    while(!file.eof()){
        char u,v;
        int w;
        file >> u >> v >> w;
        graph[mp[u]][mp[v]]=w;
        graph[mp[v]][mp[u]]=w;
    }
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<< graph[i][j] << " ";
        }cout<<endl;
    }

    

}

int extractMin(int key[], bool mstSet[]){
    int min = INT_MAX , minVer= -1;
    for(int i=0;i<vertices;i++){
        if(key[i]< min && mstSet[i]==false){
            min = key[i];
            minVer = i;
        }
    }
    return minVer;
}
void printGraph(int parent[],int key[]){
    for(int i=1;i<vertices;i++){
        cout<< parent[i]<< " - "<< i << "  "<< graph[parent[i]][i]<< endl;
    }
}

void primsAlgo( ){
    int key[vertices], parent[vertices];
    bool mstSet[vertices];
    for(int i=0;i<vertices;i++){
        key[i]= INT_MAX;
        parent[i]=-1;
        mstSet[i]= false;
    }
    key[0]= 0;
    for(int i=0;i<vertices;i++){
        int u = extractMin(key,mstSet);
        cout<< u <<" -"<<" u"<<endl;
        for(int i=0;i<vertices;i++){
            if(graph[u][i] && key[i]>graph[u][i] && mstSet[i]==false){
                parent[i]=u;
                key[i]=graph[u][i];

                cout<< "key"<<i<<"-"<<key[i]<<"   "<<u<<"    "<<i<< endl<<endl;
            }
        }
        mstSet[u]=true;
    }
    // for(int i=0;i<vertices;i++){
    //     cout<< "key"<<i<<"-"<<key[i]<<endl;
    // }
    cout<< endl;
    printGraph(parent,key);

 
    
}


int main()
{
    read();
    primsAlgo();
}