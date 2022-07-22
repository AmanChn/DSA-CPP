#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // 123 n
    // 456 n
    // 789 n
    
    int n,count=1;
    cin>>n;
    
    
    for(int i=1;i<=n;i++){     //for no. of rows
        for(int j=1;j<=n;j++){  // for no. of columns in each row
            cout<<count<<" ";
            count++;
        }
        cout<<endl; // to get to new line.
    }

    return 0;
}
