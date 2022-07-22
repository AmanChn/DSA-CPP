#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // 1
    // 22
    // 333
    // 4444
    
    int n;
    cin>>n;
    
    
    for(int i=1;i<=n;i++){     //for no. of rows
        for(int j=1;j<=i;j++){  // for no. of columns in each row
            cout<<i;
            
        }
        cout<<endl; // to get to new line.
    }

    return 0;
}
