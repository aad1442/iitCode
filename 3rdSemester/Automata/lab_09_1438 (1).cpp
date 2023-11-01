#include<bits/stdc++.h>
using namespace std ;

string revStr( string input )
{
    string reve = "" ;
    for ( int i = input.length()-1; i >= 0 ; i-- )
    {
        reve += input[i] ;
    }
    return reve ;
}

bool match = false ;
string str, newStr = "" , output[10];
int l ;

void callP( int i )
{
    string reverseStrg = revStr(newStr) ;
    if( newStr + reverseStrg == str )
    {
        output[i+1] = newStr + reverseStrg ;
        match = true ;
        return ;
    }
    if( newStr + "0" + reverseStrg == str )
    {
        output[i+1] = newStr + "0" + reverseStrg ;
        match = true ;
        return ;
    }
    if( newStr + "1" + reverseStrg == str )
    {
        output[i+1] = newStr + "1" + reverseStrg ;
        match = true ;
        return ;
    }
    if( i > l/2 ) return ;
    else
    {
        if( str[i] == '0' )
        {
            newStr += "0";
            output[i+1] = newStr + "P" + revStr(newStr) ;
            i++ ;
            callP( i );
        }
        else if( str[i] == '1' )
        {
            newStr += "1";
            output[i+1] = newStr + "P" + revStr(newStr) ;
            i++ ;
            callP( i );
        }
    }
    return ;
}

int main()
{
    string  P = "P", preStr = "", postStr = "" ;
    cout << "Input : " ;
    cin >> str ;
    l = str.length() ;
    output[(l/2) + 2] ;

    for ( int i = 0; i < str.length(); i++ )
    {
        if( str[i]!= '0' && str[i]!= '1')
        {
            cout << "Invalid input." ;
            return 0 ;
        }
    }

    output[0] = "P" ;
    callP( 0 );
    
    if ( !match ) cout << "Output : Not in this grammar.\n" ;
    else
    {
        cout << "Output : " ;
        for ( int i = 0; i < (l/2)+1; i++ )
        {
            cout << output[i] << " => " ;
        }
        cout << output[(l/2)+2] << endl ;
        
        // cout << P << " => " ;
        // for ( int i = 0; i < str.length()/2; i++)
        // {
        //     preStr = preStr + str[i] ;
        //     postStr = str[i] + postStr ;
        //     cout << preStr+P+postStr << " => " ;
        // }
        // if( str.length()%2 == 0 )
        //     cout << preStr+postStr << endl ;
        // else
        // {
        //     P = str[str.length()/2];
        //     cout << preStr + P + postStr << endl ;
        // }        
        
    }

}