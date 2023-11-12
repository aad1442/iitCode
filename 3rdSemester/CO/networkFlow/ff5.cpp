#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

const int maxV = 20;
int numV, numE;
int graph[maxV][maxV] = {0};
int previous[maxV];
bool visited[maxV];

bool bfs(int source, int sink);
int fordFulkerson(int source, int sink);
void read();
void print();


void printpath(int source, int sink){
    if(sink==-1)
        return;
    printpath(source,previous[sink]);
    cout<<" "<< sink<< " ";
}


bool bfs(int source, int sink) {
    for (int i = 0; i < numV; i++) {
        visited[i] = false;
    }
    queue<int> myQueue;
    myQueue.push(source);
    visited[source] = true;
    previous[source] = -1;

    while (!myQueue.empty()) {
        int u = myQueue.front();
        myQueue.pop();
        for (int i = 0; i < numV; i++) {
            if (!visited[i] && graph[u][i]) {
                myQueue.push(i);
                visited[i] = true;
                previous[i] = u;
            }
        }
    }
    return visited[sink];
}

int fordFulkerson(int source, int sink) {

    int maxFlow = 0;
    while (bfs(source, sink)) {
        int minCapacity = INT_MAX;
        for (int i = sink; i != source; i = previous[i]) {
            int parent = previous[i];
            minCapacity = min(minCapacity, graph[parent][i]);
        }
        maxFlow += minCapacity;

        for (int i = sink; i != source; i = previous[i]) {
            int parent = previous[i];
            graph[parent][i] -= minCapacity;
        }
        printpath(source,sink);
        cout<<"      " <<minCapacity <<endl;
    }
    cout<<endl<< "Maximum flow is : "<< maxFlow <<endl;
    return maxFlow;
}

void read() {
    ifstream myfile("ford.txt");
    myfile >> numV >> numE;
    int u, v, w;
    for (int i = 0; i < numE; i++) {
        myfile >> u >> v >> w;
        graph[u][v] = w;
    }
}

void print() {
    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < numV; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    read();
    print();
    cout <<endl<<endl << endl;
    cout << " Flow: \n"  << endl;
    fordFulkerson(0, 5);
}