#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#define Max 10

int numStates, numAlphabet;
string state[Max], alphabet[Max], start, finish;
char tran[Max][Max][Max];
vector<string> dfaState;
map<string, vector<string>> Dfa;

string mapSearch()
{
    for (const auto &entry : Dfa)
    {
        for (const string &transition : entry.second)
        {
            bool isInDfaState = false;
            for (const string &inDfaState : dfaState)
            {
                if (inDfaState == transition)
                {
                    isInDfaState = true;
                    break;
                }
            }
            if (!isInDfaState)
            {
                // Found an unprocessed transition
                return transition;
            }
        }
    }

    // If no unprocessed transition is found, return "-1"
    return "-1";
}

void dfaPrinting()
{
    for (const auto &entry : Dfa)
    {
        cout << entry.first << " -> ";
        for (const string &transition : entry.second)
        {
            cout << transition << " ";
        }
        cout << endl;
    }

    cout<<"Now I have successfully printed the dfa"<<endl;
}

int indexShow(string given)
{
    for (int i = 0; i < numStates; i++)
    {
        if (state[i] == given)
        {
            return i;
        }
    }
    return -1; // Return -1 if the state is not found
}

void dfaMaking()
{
    cout<<"dfaMaking started"<<endl;
    dfaState.push_back(start);
    int startIndex = indexShow(start);

    vector<string> temp;
    for (int i = 0; i < numAlphabet; i++)
    {
        string s = "";
        for (int j = 0; tran[startIndex][i][j]; j++)
        {
            s += tran[startIndex][i][j];
        }
        temp.push_back(s);
    }
    Dfa.insert({start, temp});
    cout<<Dfa.size()<<endl;
    string newState;
    int p=0;
    while ((newState = mapSearch()) != "-1")
    {
        cout<<"newState: "<<newState<<endl;
        vector<string> temp;
        for (int i = 0; i < numAlphabet; i++)
        {
            string s = "";
            for (int j = 0; newState[j]; j++)
            {
                int index = indexShow(string(1, newState[j]));

                for (int k = 0; tran[index][i][k]; k++)
                {
                    s += tran[index][i][k];
                }
            }
            temp.push_back(s);
        }
        Dfa.insert({newState, temp});
        cout<<"DFasize"<<Dfa.size()<<endl;
        cout<<"DFaStatesize"<<dfaState.size()<<endl;
        dfaState.push_back(newState); // Don't forget to add the new state to the list of processed states
        p++;
        if(p==5)break;
    
    }


    cout<<"Successfully dfa making done"<<endl;
}

void nfaInput()
{
    ifstream myfile("nfaInput.txt");

    if (!myfile.is_open())
    {
        cout << "Failed to open the file" << endl;
        return;
    }
    myfile >> numStates >> numAlphabet;
    cout << numStates << endl
         << numAlphabet << endl;

    // Input state names
    for (int i = 0; i < numStates; i++)
    {
        myfile >> state[i];
        cout << " state " << i + 1 << ": " << state[i] << endl;
    }

    // Input alphabet symbols
    for (int j = 0; j < numAlphabet; j++)
    {
        myfile >> alphabet[j];
        cout << "Alphabet: " << alphabet[j] << endl;
    }

    for (int i = 0; i < numStates; i++)
    {
        for (int j = 0; j < numAlphabet; j++)
        {
            int t;
            myfile >> t;
            for (int k = 0; k < t; k++)
            {
                myfile >> tran[i][j][k];
            }
        }
    }

    cout << "Transition table:" << endl;

    for (int i = 0; i < numStates; i++)
    {
        cout << " " << state[i] << "  : ";
        for (int j = 0; j < numAlphabet; j++)
        {
            for (int k = 0; tran[i][j][k]; k++)
            {
                cout << tran[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    myfile >> start;
    cout << "Start: " << start << endl;
    myfile >> finish;
    cout << "Finish: " << finish << endl;
    cout<<"done"<<endl;
}

int main()
{
    nfaInput();
    dfaMaking();
    dfaPrinting();

    return 0;
}
