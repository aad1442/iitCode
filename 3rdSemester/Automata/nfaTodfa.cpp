#include <iostream>
#include <fstream>
#include<vector>
#include<map>
using namespace std;

#define Max 10

int numStates, numAlphabet;
string state[Max], alphabet[Max], start, finish;
char tran[Max][Max][Max];
vector<string> dfaState;
map<string,vector<string>> Dfa;


string mapSearch() {
    for (const auto& entry : Dfa) {
        for (const string& transition : entry.second) {
            bool isInDfaState = false;
            for (const string& inDfaState : dfaState) {
                if (inDfaState == transition) {
                    isInDfaState = true;
                    break;
                }
            }
            if (!isInDfaState) {
                // Found an unprocessed transition
                return transition;
            }
        }
    }

    // If no unprocessed transition is found, return a special value
    return "-1";
}


void dfaMaking(){
    dfaState.push_back(start);
    int startIndex=-1;
    for(int i=0;i<numStates;i++){
        if(state[i]==start){
            startIndex=i;
            break;
        }
    }
    vector<string>temp;
    for(int i=0;i<numAlphabet;i++){
        string s="";
        for(int j=0;tran[startIndex][i][j];j++){
            s += tran[startIndex][i][j];
        }
        temp.push_back(s);
    }
    Dfa.insert({start,temp});
    string newState;
    while((newState=mapSearch()) != "-1"){
        string s[numAlphabet];
        for(int i=0;newState[i];i++){

            int index =-1;
            for(int j=0;j<numStates;j++){
                if(state[j]==string(1,newState[i])){
                    index = j;
                    break;
                }
            }
            


        }
    }
   
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
    cout<<numStates <<endl<<numAlphabet<<endl;
    // cout << "Enter number of states: ";
    // cin >> numStates;
    // cout << "Enter number of Alphabets: ";
    // cin >> numAlphabet;

    // Input state names
    for (int i = 0; i < numStates; i++)
    {
        
        myfile >> state[i];
        cout << " state " << i + 1 << ": "<<state[i]<<endl;
    }

    // Input alphabet symbols
    for (int j = 0; j < numAlphabet; j++)
    {
        // cout << "Enter name for alphabet " << j + 1 << ": ";
        myfile >> alphabet[j];
        cout<< "Alphabet: "<<alphabet[j]<<endl;
    }

    // cout << "Enter the transition table: " << endl;

    for (int i = 0; i < numStates; i++)
    {
        for (int j = 0; j < numAlphabet; j++)
        {
            // cout << "For state " << state[i] << " and alphabet " << alphabet[j] << ": Enter number of transitions: ";
            int t;
            myfile >> t;
            for (int k = 0; k < t; k++)
            {
                // cout << "Enter transition for state " << state[i] << " and alphabet " << alphabet[j] << " to state: ";
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
            for (int k = 0; k < tran[i][j][k]; k++)
            {
                cout << tran[i][j][k] << "";
            }cout<<" ";
        }
        cout << endl;
    }
     // cout<<"Enter the start index: "<<endl;
    myfile >> start;
    cout<<"Start: "<<start<<endl;
    // cout<<"Enter the endding state: "<<endl;
    myfile >> finish;
    cout<<"Finish: "<<finish<<endl;
}

int main()
{

    nfaInput();

    return 0;
}
