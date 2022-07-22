#include <iostream>

using namespace std;


int no1(int n){
    
    int rem;
    int count=0;
    while(n!=0){
        
        rem=n%10;
        if(rem==1){
            count++;
        }
        n=n/10;
        
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int ans = no1(n);
    cout<<ans;

    return 0;
}
