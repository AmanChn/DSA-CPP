// Euclids GCD (greatest coomon divisor) (hcf)

#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    //using iteration
    // if(a==0)
    //     return b;
        
    // if(b==0)
    //     return a;
    
    // while(a!=b){
    //     if(a>b){
    //         a=a-b;
    //     }
        
    //     if(b>a){
    //         b=b-a;
    //     }
        
    // } 
    // return a;
    
    //using recursion
    if(a == 0)
        return b;
    
    return gcd(b%a,a);
}


int main()
{
    int a,b;
    cout<<"Enter two numbers :";
    cin>>a;
    cin>>b;
    
    int ans = gcd(a,b);
    
    cout<<"Euclids GCD for "<<a<<" and "<<b<<" is :"<< ans<<endl; 

    // hcf * lcm = product of numbers;
    int lcm = (a*b)/ans;
    
    cout<<"LCM of "<<a<<" and "<<b<<" is "<<lcm;
    
    return 0;
}
