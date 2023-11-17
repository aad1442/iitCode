#include <bits/stdc++.h>
using namespace std;

#define Max 20

map<string, int> names;
int D[Max][Max];
int graph[Max][Max] = {INT_MAX};
int p[Max][Max];

void readString()
{
    string s;
    int w, x, y, i = 0;
    ifstream myfile("floyedWarshall1.txt");

    if (!myfile.is_open())
    {
        cerr << "Failed to open the file" << endl;
        exit(1);
    }

    for (int i = 0; i < Max; i++)
    {
        for (int j = 0; j < Max; j++)
        {
            graph[i][j] = INT_MAX;
        }
    }

    while (myfile >> s)
    {
        if (s == "END")
            break;

        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        x = names[s];
        myfile >> s;

        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        y = names[s];

        myfile >> w;
        graph[x][y] = w;
        graph[x][x]=0;
    }

    cout << " file is closing " << endl;
    myfile.close();
}

void grpahPrinting(int g[Max][Max], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        for (int j = s; j <= e; j++)
        {
            cout << g[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "    ------       " << endl
         << endl;
}

void floydWarshal(int graph[Max][Max])
{
    for (int i = 1; i <= names.size(); i++)
    {
        for (int j = 1; j <= names.size(); j++)
        {
            D[i][j] = graph[i][j];
        }
    }
    cout << "D0" << endl;
    grpahPrinting(D, 1, names.size());

    for(int i=1;i<=names.size();i++){
        for(int j=1;j<=names.size();j++){
            if(i==j)p[i][j]=0;
            else p[i][j]=i;
        }
    }

    for (int k = 1; k <= names.size(); k++)
    {
        for (int i = 1; i <= names.size(); i++)
        {
            for (int j = 1; j <= names.size(); j++)
            {
                if ((D[i][k] != INT_MAX && D[k][j] != INT_MAX) && (D[i][k] + D[k][j]) < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
        cout << "D" << k << endl;
        grpahPrinting(D, 1, names.size());
    }
}

void printPath(int s,int t){
    if(p[s][t]==0){
        cout<<"No Path"<<endl;
        return;

    }
    else if(p[s][t]==s){
        cout<<"---"<<s<<"---";
    }
    else{
        printPath(s,p[s][t]);
        printPath(p[s][t],t);
    }
    cout<<"---"<<t;
}

int main()
{
    readString();
    cout << names.size() << endl;

    for (auto s : names)
    {
        cout << s.first << "     " << s.second << endl;
    }
    grpahPrinting(graph, 1, 5);
    floydWarshal(graph);
    grpahPrinting(D, 1, names.size());
    grpahPrinting(p,1,names.size());

    string source, destination;
    //int source, destination;
    cout<<"Enter Source: ";
    cin>>source;
    cout<<"Enter Destination: ";
    cin>>destination;
    cout<<names[source]<<names[destination]<<endl;
    printPath(names[source],names[destination]);
    //printPath(5,1);

    return 0;
}
