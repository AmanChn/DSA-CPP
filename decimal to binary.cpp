//Decimal to binary conversion

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 5 --- 101
   int n;
   cin>>n;
   int i=0,bit,ans=0;
   
  if(n>0){
    while(n!=0){
       bit=n&1;
       
       ans= bit * pow(10,i) + ans; // to store the individual digits in an integer
       n=n>>1;
       i++;
      }
      
    cout<<ans;
    
    }
    else{
        cout<<"negative no.";
    }
    
   



    return 0;
}
