#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
void addlist(unordered_map<T, list<T>>& adj, ifstream& inputFile) {
    int n, m;
    inputFile >> n >> m;
    for (int i = 0; i < m; i++) {
        T u, v;
        inputFile >> u >> v;
        adj[u].push_back(v);
    }
}

template <typename T>
void printList(const unordered_map<T, list<T>>& adj) {
    for (auto u : adj) {
        cout << u.first << "-->";
        for (auto v : u.second) {
            cout << " " << v;
        }
        cout << endl;
    }
}

int main() {
    ifstream MyFile("2adj.txt");
    if (!MyFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    unordered_map<int, list<int>> adj;
    addlist(adj, MyFile);
    printList(adj);

    MyFile.close();

    return 0;
}
