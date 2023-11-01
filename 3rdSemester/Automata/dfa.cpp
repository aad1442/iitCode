#include<iostream>
#include<fstream>
using namespace std;
#define Max 20

char start,finish,tran[Max][Max],state[Max],alphabet[Max];
int numState,numAlphabet;
string path = string(1,start);

void dfaReading(){
    ifstream myfile("dfaInput.txt");
    myfile>>numState;
    cout<<"Number of state: "<<numState<<endl;
    for(int i=0;i<numState;i++){
        myfile>> state[i];
        cout<<"State :"<<state[i]<<endl;
    }
    myfile>>numAlphabet;
    cout<<"Number of Alphabet: "<<numAlphabet<<endl;
    for(int i=0;i<numAlphabet;i++){
        myfile>>alphabet[i];
        cout<<"Alphabet: "<<alphabet[i]<<endl;
    }
    myfile>>start;
    cout<<"Start: "<<start<<endl;
    myfile>> finish;
    cout<<"Finish: "<<finish<<endl;

    for(int i=0;i<numState;i++){
        for(int j=0;j<numAlphabet;j++){
            myfile>>tran[i][j];
        }
    }

    cout<<"Transition Table: "<<endl;

    for(int i=0;i<numState;i++){
        cout<<state[i]<<"  ";
        for(int j=0;j<numAlphabet;j++){
            cout<<" "<<tran[i][j];
        }cout<<endl;
    }
    
}

char dfa(string str){
    int sL = str.length();
    char currState=start;
    for(int i=0;i<sL;i++){
        int curStateIndex,alphaIndex;
        for(int j=0;j<numState;j++){
            if(currState==state[j]){
                curStateIndex=j;
                break;
            }
        }
        for(int j=0;j<numAlphabet;j++){
            if(str[i]==alphabet[j]){
                alphaIndex = j;
                break;
            }
        }
        currState = tran[curStateIndex][alphaIndex];
        path = path+"->"+currState;
        
        cout<<"From "<<state[curStateIndex]<<"  getting  "<<alphabet[alphaIndex]<<"  -> "<<currState<<endl;
    }
    return currState;
}

int main(){
    string input;
    char finishing;
    dfaReading();
    cout<<"Enter a string: ";
    cin>>input;
    finishing=dfa(input);
    if(finishing==finish){
        cout<<"Accepted"<<endl;
        cout<<"Path :"<<path<<endl;
    }else{
        cout<<"Not accepted"<<endl;
    }
}