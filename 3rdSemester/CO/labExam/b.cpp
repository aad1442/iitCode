#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int numVertices, numEdges;
set<int> vertices;
set<pair<int, pair<int, int>>> edges;
set<pair<int, pair<int, int>>> A;
vector<set<int>> sets;
vector<int> prices;

void makeSet(int s)
{
    set<int> temp;
    temp.insert(s);
    sets.push_back(temp);
}

void getInput()
{
    fstream myfile("test5.txt");
    if (!myfile.is_open())
    {
        cerr << "Failed to open the file" << endl;
        exit(1);
    }

    myfile >> numVertices >> numEdges;
    prices.assign(numVertices + 1, 0);
    for (int i = 1; i <= numVertices; i++)
    {
        myfile >> prices[i];
    }
    int s;
    int w = 1;
    for (int i = 1; i <= numVertices; i++)
    {
        vertices.insert(i);
    }

    for (int i = 0; i < numEdges; i++)
    {
        pair<int, int> temp;
        myfile >> s;
        temp.first = s;
        myfile >> s;
        temp.second = s;
        edges.insert({w, temp});
    }

    cout << " file is closing " << endl;
    myfile.close();
}

void edgePrinting(const set<pair<int, pair<int, int>>> &e)
{
    for (pair<int, pair<int, int>> p : e)
    {
        cout << p.second.first << "     " << p.second.second << "-->" << p.first << endl;
    }
}

void verticesPrinting()
{
    for (int v : vertices)
    {
        cout << "  " << v << endl;
    }
}

int findSet(int u)
{
    int count = 0;
    int flag = 0;
    for (auto i : sets)
    {
        auto a = i.find(u);
        if (a != i.end())
        {
            flag = 1;
            break;
        }
        count++;
    }
    if (flag)
        return count;
    else
        return -1;
}

void NotInMST()
{
    for (int i : vertices)
    {
        int j = findSet(i);
        //cout<<"j"<<j<<endl;
        if (j == -1)
        {
            cout << "Others: " << i << endl;
        }
    }
}

void minimumCost(){
    int cost=0;
    for(auto i:sets){
        int mincost = 500;
        for(int j:i){
            if(prices[j]<mincost){
                mincost = prices[j];
            }

        }
        cost +=mincost;
    }
    cout<<"MinCost :"<<cost<<endl;
}

void uni(int u, int v)
{
    set<int> temp;
    int index_u = findSet(u);
    int index_v = findSet(v);

    for (auto a : sets[index_v])
    {
        sets[index_u].insert(a);
    }

    sets.erase(sets.begin() + index_v);
}

void MST()
{
    for (int vertex : vertices)
    {
        makeSet(vertex);
    }
    for (auto i : edges)
    {
        int u, v;
        u = i.second.first;
        v = i.second.second;
        if (findSet(u) != findSet(v))
        {
            A.insert(i);
            uni(u, v);
        }
    }
}

int main()
{
    getInput();
    cout << numVertices << "  uygt   " << numEdges << endl;

    edgePrinting(edges);
    cout << endl
         << endl
         << endl;
    verticesPrinting();
    cout << endl
         << endl
         << endl;
    MST();
    cout << "Minimum Spanning Tree :" << endl;
    edgePrinting(A);

    cout << endl
         << endl
         << endl;
    NotInMST();
    minimumCost();
}
