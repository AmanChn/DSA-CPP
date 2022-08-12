
#include <bits/stdc++.h>

using namespace std;

int costValid(string s){
    //if odd size it is impossible to make it valid
    if(s.size() % 2 != 0){
        return -1;
    }
    
    stack<char> st;
    
    for(int i=0 ;i < s.size() ; i++){
        
        char ch = s[i];
        
        if(ch == '{' ){
            st.push(ch);
        }
        else{
            // ch is closed brace
            if(!st.empty()  && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    
    // stack contains invalid expression
    int a = 0 , b = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        st.pop();
    }
    
    // formula to calculate no. of changes 
    int ans = (a+1)/2 + (b+1)/2
    
    return ans;
    
}


int main()
{
    string s = "{{{}{}";
    
    cout<<"cost of making string valid : "<<costValid(s);

    return 0;
}
