#include <iostream>
#include <vector>
#include <string>
#define Max 10
using namespace std;

vector<string> variable;

int main()
{
    int numVar, numEq;
    cout << "Enter the number of variables in z :";
    cin >> numVar;
    cout << "Enter the number of Equations :";
    cin >> numEq;
    for (int i = 1; i <= numVar; i++)
    {
        variable.push_back("x" + to_string(i));
    }
    for (int j = 1; j <= numEq; j++)
    {
        variable.push_back("s" + to_string(j));
    }

    for (int i = 0; i < variable.size(); i++)
    {
        cout << variable[i] << endl;
    }
    // for (const string& var : variable) {
    //     cout << var << endl;
    // }

    int equations[numEq + 1][numVar + numEq + 1];
    for (int i = 0; i < numEq + 1; i++)
    {
        for (int j = 0; j < numVar + numEq + 1; j++)
        {
            equations[i][j] = 0;
        }
    }

    for (int i = 0; i < numEq + 1; i++)
    {
        if (i == 0)
        {
            cout << "z ==" << endl;
            for (int j = 0; j < numVar; j++)
            {
                cout << "Enter the coefficient of" << variable[j] << " :";
                cin >> equations[i][j];
                equations[i][j] = -equations[i][j];
            }
        }
        else
        {
            cout << "Equation " << i << " :" << endl;
            for (int j = 0; j < numVar; j++)
            {
                cout << "Enter the coefficient of" << variable[j] << " :";
                cin >> equations[i][j];
            }
            cout << "Enter the RHS :";
            cin >> equations[i][numEq + numVar];
            equations[i][i+numVar-1]=1;
        }
    }

    for(int i=0;i<numEq+1;i++){
        if(i==0){
                cout<<"z ";
            }
        for(int j=0;j<numEq+numVar+1;j++){
            if(j==numEq+numVar)cout<<"=";
            cout<<equations[i][j]<<variable[j]<<" ";

        }cout<<endl;
    }




}