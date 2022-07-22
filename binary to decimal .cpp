//Binary to decimal conversion

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //  101 --- 5
   int n;
   cin>>n;
   int i=0,digit,ans=0;
   
  if(n>0){
    while(n!=0){
        digit = n%10;
        
        if(digit==1){
            ans = ( digit * pow(2,i) ) + ans;
        }
        n=n/10;
        i++;
      }
      
    cout<<ans;

    }
    else{
        cout<<"negative number";
    }


    return 0;
}
