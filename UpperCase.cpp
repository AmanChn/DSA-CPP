#include <bits/stdc++.h>

using namespace std;

string toLowerCase( string s ){
    for(int i =0 ; i<s.size() ; i++){
            if( s[i] >='A' && s[i] <='Z' ){
                s[i] =  'a' + ( s[i] - 'A' ) ;
                // this diff will be added in form of number to get the ascii value of lowercase letter.         
                
            }
    }
    
    return s;

}


string toUpperCase( string s ){
    for(int i =0 ; i<s.size() ; i++){
            if( s[i] >='a' && s[i] <='z' ){
                s[i] =  'A' + ( s[i] - 'a' );
            }
    }
    
    return s;

}


int main()
{
    string s = "AmANcHAuHaN";
    
    cout<<toLowerCase(s)<<endl;
    cout<<toUpperCase(s);

    return 0;
}
