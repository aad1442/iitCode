#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cmath>

using namespace std;

const int numStrings = 5;
string str[numStrings];
char sigma[]={'0','1'};


void generateFiveStrings(char alphabet[]){
    for(int i=0;i<numStrings;i++){
        int n= 2 + rand()%20;
        for(int j=0;j<n;j++){
            str[i]+=alphabet[rand()%(sizeof(sigma)/sizeof(sigma[0]))];
        }
        cout<<"String "<<i+1<< " - "<<str[i]<<endl;
    }
    cout<<endl<<endl<<endl;
}


void printingSigmaToThePowerK(){
    cout<< "Enter the value of k :"<<endl;
    int k;
    cin >> k;
    if(k == 0){
        cout << "{e}"<< endl;
    }else{
        int values = pow(2,k);
        vector <string> arr(values,string(k,'0'));
        cout << "{ ";
        for(int i =0;i<values;i++){
            int temp = i;
            for(int j=k-1;j>=0;j--){
                arr[i][j]= temp%2 + '0';
                temp /=2;
            }
            cout<< arr[i];
            if(i<values-1){
                cout<< ", ";
            }

        }
        cout<< " }"<<endl;
    }
}


void printLength(char alphaber[]){
    for(int i=0;i<numStrings;i++){
        cout<< "Length of string" << i+1<< " - "<< str[i].length() << endl;
    }
    cout<<endl<< endl<< endl;
}



void isFromTheAlphabet(string w){
    int i=0;
    while(w[i] != '\0'){
        if(!(w[i]=='0' || w[i] =='1')){
            cout<< "The string is not from the alphabet. "<< endl;
            return;
        }
        i++;

    }
    cout<< "The string is in the alphabet ."<<endl;
    
}

void stringConcatenation(string &a, string &b){
    int l = a.length();
    int l2 = b.length();
    char z[l+l2+1];
    int j=0;
    
    for(int i=0;i<l;i++,j++){
        z[j]=a[i];
    }
    for(int i=0;i<l2;i++,j++){
        z[j]=b[i];
    }z[j]='\0';

    cout<< "Concatenated String: "<<z <<endl;
}

void identifingPalindrome(string s){
    int l=s.length()/2;
    for(int i=0;i<l;i++){
        if(s[i]!=s[s.length()-i-1]){
            cout<< "It's not palindrome . "<< endl;
            return;
        }
        
    }
    cout<< "It's palindrome. "<< endl;
    return;

}


int main(){
    srand(static_cast<unsigned>(time(0)));
    generateFiveStrings(sigma);
    printLength(sigma);
    isFromTheAlphabet(str[1]);
    stringConcatenation(str[2],str[3]);
    printingSigmaToThePowerK();
    identifingPalindrome(str[2]);

}