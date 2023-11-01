#include <iostream>
#include<fstream>
using namespace std;

#define Max 10

int numStates, numAlphabet;
char state[Max], alphabet[Max],start,finish;
char tran[Max][Max][Max];
int stringLength;
string str;
string path;
bool found = false;
void nfa(char presentState,int presentIndex, string currentPath){
    
    if(presentIndex == stringLength && presentState == finish){
        found = true;
        path = currentPath;
        return;
    }
    if(presentIndex >= stringLength){
        //cout<< "Index out of bound "<<endl;
        return;
    }

    int presentStateIndex=-1;
    for(int i=0;i<numStates;i++){
        if(state[i]==presentState){
            presentStateIndex = i;
            break;
        }
    }

    if (presentStateIndex == -1) {
        cout<< "presentStateIndex == -1 "<<endl;
        return;
    }

    int alphabetIndex;
    for(int i=0;i<numAlphabet;i++){
        if(str[presentIndex]==alphabet[i]){
            alphabetIndex = i;
        }
    }

     if (alphabetIndex == -1) {
        cout<< "alphabetIndex == -1 "<<endl;
        return;
    }
    for(int i=0;i<tran[presentStateIndex][alphabetIndex][i];i++){
        nfa(tran[presentStateIndex][alphabetIndex][i],presentIndex+1,currentPath+" "+tran[presentStateIndex][alphabetIndex][i]);
    }
}

void nfaInput(){
    ifstream myfile("nfaInput.txt");

    if(!myfile.is_open()){
        cout<<"Failed to open the file"<<endl;
        return;
    }
    myfile >> numStates >> numAlphabet;

    // cout << "Enter number of states: ";
    // cin >> numStates;
    // cout << "Enter number of Alphabets: ";
    // cin >> numAlphabet;

    // Input state names
    for (int i = 0; i < numStates; i++) {
        //cout << "Enter name for state " << i + 1 << ": ";
        myfile >> state[i];
    }

    // Input alphabet symbols
    for (int j = 0; j < numAlphabet; j++) {
        //cout << "Enter name for alphabet " << j + 1 << ": ";
        myfile >> alphabet[j];
    }

   // cout << "Enter the transition table: " << endl;

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numAlphabet; j++) {
            //cout << "For state " << state[i] << " and alphabet " << alphabet[j] << ": Enter number of transitions: ";
            int t;
            myfile >> t;
            for (int k = 0; k < t; k++) {
                //cout << "Enter transition for state " << state[i] << " and alphabet " << alphabet[j] << " to state: ";
                myfile >> tran[i][j][k];
            }
        }
    }

    //cout<<"Enter the start index: "<<endl;
    myfile>>start;
    //cout<<"Enter the endding state: "<<endl;
    myfile >>finish;

    cout << "Transition table:" << endl;

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numAlphabet; j++) {
            cout << "For state " << state[i] << " and alphabet " << alphabet[j] << ": ";
            for (int k = 0; k < tran[i][j][k]; k++) {
                cout << tran[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    cout<<"Starting State: "<<start << endl;
    cout<<"Finishing State: "<<finish <<endl;

}

int main() {
    
    nfaInput();

    cout<<"Enter the String : ";
    cin>> str;
    stringLength=str.length();
    nfa('a',0,"a");
    stringLength= str.length();
    if(found){
        cout<<"The string is in the language. "<<endl;
        cout<< "path: "<<path<<endl;
    }else
        cout<<"Invalid string."<<endl;
    return 0;
}
