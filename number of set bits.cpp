// to find the total number of set bits
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    
                       
    int counter=0;
    
    while(a!=0 || b!=0){
        if(a&1==1){
            counter++;
        }
        a=a>>1;
        
        if(b&1==1){
            counter++;
        }
        b=b>>1;
        
    }
     cout<<"total set bits:" <<counter<<endl;

    return 0;
}
