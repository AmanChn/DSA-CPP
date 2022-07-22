// fast exponentiation

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,n,m;
    cout<<"Entr the value of x,n,m - (x^n)mod(m) :" ;
    cin>>x>>n>>m; 

    //fast exponentiation states that:
    // a^b = a^(b/2)^2; if even
    // a^b = a^(b/2)^2 * a ; if odd
    
    
    int res=1;
    
    while(n>0){
        if(n&1){ //odd
            res = (res * (x)%m)%m;
        }
        x =((x)%m * (x)%m)%m;
        
        n=n>>1; // divide by 2
        
    }
    
    cout<<res;

        
    return 0;
}
