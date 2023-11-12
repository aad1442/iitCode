#include<iostream>
#include<fstream>
#include<map>
#include<cmath>
using namespace std;

#define Max 20


map<string,int> names;
int D[Max][Max];
int graph[Max][Max];
int pre[Max][Max];

void readString(){
    string s;
    int w,x,y,i=0;
    ifstream myfile("floyedWarshall1.txt");

    if(!myfile.is_open()){
        cerr<<"Failed to open the file"<<endl;
        exit(1);
    }

    while(myfile>>s){
        if(s == "END") break;

        if(names[s]==0){
            names[s]== +i;
        }
        x = names[s];
        myfile >> s;

        if(names[s] == 0){
            names[s] = ++i;
        }
        y = names[s];

        myfile >> w;

        graph[x][y] = w;
    }

    cout<<" file is closing "<< endl;
    myfile.close();
}