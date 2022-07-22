#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // 1 
    // 2 1 
    // 3 2 1 
    // 4 3 2 1
    
    int n;
    cin>>n;
    int count;
    
    for(int i=1;i<=n;i++){     //for no. of rows
        count=i;
        for(int j=1;j<=i;j++){  // for no. of columns in each row
            cout<<count<<" ";
            count--;
        }
        
        cout<<endl; // to get to new line.
    }

    return 0;
}
