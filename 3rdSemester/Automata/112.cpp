#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define Max 10

int numStates, numAlphabet;
string state[Max], alphabet[Max], start, finish;
char tran[Max][Max][Max];
vector<string> dfaState;
map<string, vector<string>> Dfa;
set<string> processedStates;

string mapSearch()
{
    for (const auto &entry : Dfa)
    {
        if (processedStates.find(entry.first) == processedStates.end()) {
            return entry.first;
        }
    }

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

    cout << "Now I have successfully printed the DFA" << endl;
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
    cout << "DFA Making started" << endl;
    dfaState.push_back(start);

    while (true)
    {
        string currentNFAState = mapSearch();
        if (currentNFAState == "-1")
            break;

        processedStates.insert(currentNFAState);

        vector<string> temp;
        for (int i = 0; i < numAlphabet; i++)
        {
            set<char> combinedTransitions;
            for (char c : currentNFAState)
            {
                int nfaIndex = indexShow(string(1, c));
                for (int j = 0; tran[nfaIndex][i][j]; j++)
                {
                    combinedTransitions.insert(tran[nfaIndex][i][j]);
                }
            }
            string combinedTransitionState = "";
            for (char c : combinedTransitions)
            {
                combinedTransitionState += c;
            }
            temp.push_back(combinedTransitionState);
        }
        Dfa.insert({currentNFAState, temp});
    }

    cout << "Successfully DFA making done" << endl;
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
        cout << "State " << i + 1 << ": " << state[i] << endl;
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
    cout << "Done" << endl;
    myfile.close();
}

int main()
{
    nfaInput();
    dfaMaking();
    dfaPrinting();

    return 0;
}
