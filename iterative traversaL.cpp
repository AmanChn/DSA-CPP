// iterative preorder traversal

void iterative(Node* root , vector<int> &pre_store){
        // iterative traversal using stack
        stack<Node*> s;
        s.push(root);
        
        while( !s.empty() ){
            auto top = s.top();
            s.pop();
            
            pre_store.push_back(top->val);
            
 	    // first push right then left as its a stack , it will get oit in reversed order
	    if (top ->right)
               s.push(top ->right);
            if (top ->left)
               s.push(top ->left);	

	    // for n-ary tree
            for(int i=top->children.size()-1 ; i>=0 ; i--){
                s.push(top->children[i]);
            }
        }        
}



// Iterative Inorder Traversal ( to do without stack, use morris traversal )

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        
        while( curr!= NULL || !s.empty() ){

            while( curr != NULL ){
                s.push(curr);
                curr = curr->left;`
            }
            
            curr = s.top();
            s.pop();
            
            inorder.push_back(curr->val);
            
            curr = curr->right;
            
        }
        
        return inorder;
 }


// Iterative Postorder Traversal

void iteration(Node* root, vector<int> &ans){
        stack<Node*> s1;
        // stack<Node*> s2;
        
        s1.push(root);
        
        while( !s1.empty() ){
            
            Node* top = s1.top();
            s1.pop();
            
            // s2.push(top);
            ans.push_back(top->val);
            
            for(auto child : top->children){
                s1.push(child);
            }
        }
        
        // while( !s2.empty() ){
        //     ans.push_back(s2.top()->val);
        //     s2.pop();
        // }
        
        reverse(ans.begin() , ans.end());
        
    }

