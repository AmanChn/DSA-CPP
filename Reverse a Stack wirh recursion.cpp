
class Solution{
public:
    void insertAtBottom(stack<int> &st , int num){
        //base case
        if(st.empty()){
            st.push(num);
            return ;
        }
        
        int a = st.top();
        st.pop();
        
        insertAtBottom(st,num);
        
        st.push(a);
        
    }
    
    void Reverse(stack<int> St){
        if(St.empty()){
            return ;
        }
        
        int num = St.back();
        St.pop_back();
        
        Reverse(St);
        
        insertAtBottom(St,num);
        
    }
};