#include <iostream>

using namespace std;

int main()
{
    // pattern :
    // A A A
    // B B B
    // C C C 
    
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){     //for no. of rows
        for(int j=1;j<=3;j++){  // for no. of columns in each row
            char ch = 'A'+i-1;  // to get the required alphabet
            cout<<ch;
        }
        
        cout<<endl; // to get to new line.
    }

    return 0;
}
