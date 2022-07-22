#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // 1
    // 23
    // 456
    // 78910
    
    int n;
    cin>>n;
    int count=1;
    
    for(int i=1;i<=n;i++){     //for no. of rows
        for(int j=1;j<=i;j++){  // for no. of columns in each row
            cout<<count<<" ";
            count++;
        }
        cout<<endl; // to get to new line.
    }

    return 0;
}
