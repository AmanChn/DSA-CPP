#include <iostream>

using namespace std;

int main()
{
    // pattern :
    //   1
    //  121
    // 12321
    //1234321
    
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){     //for no. of rows
        
        
        // print the space (ist traingle)
        int space = n-i;
        
        while(space){
            cout<<" ";
            space--;
        }
        
        
        // print the 2nd triangle
        for(int k=1;k<=i;k++){
            cout<<k;
        }
        
        
        // print the 3rd triangle
        int start=i-1;
        while(start){
            cout<<start;
            start--;
        }
        
        cout<<endl; // to get to new line.
    }

    return 0;
}
