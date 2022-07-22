
#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // 111
    // 222
    // 333
    
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){  //for no. of rows
        for(int j=1;j<=3;j++){  // for no. of columns in each row
            cout<<i;
        }
        cout<<endl; // to get to new line.
    }
    

    return 0;
}
