    // using stack
    queue<int> reverse(quque<int> Q){
    stack<int> s;
    
    while(Q!= empty()){
        int element = Q.front();
        s.push(element);
        Q.pop();
    }
    
    while(s!= empty()){
        int element = s.top();
        Q.push(element);
        s.pop();
    }
    
    return Q;
    }
    
    
    
    // using recursion
    void reverse(queue<int> &q){
    // using recursion
    //base case
    if(q.empty()){
        return;
    }
    
    int element = q.front();
    q.pop();
    
    reverse(q);
    q.push(element);

}
