void morrisTravrersalInorder(Node* root){
    Node* curr = root;
    // inorder traversal LNR

    while(curr){ // while curr != nULL
        if(curr->left == NULL){  // if there is no subtree of curr then print it. and move to right
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{  // if curr has a left node
            Node* pred = curr->left; //to find out the predecessor of current ie the rightmost element
            
            while(pred->right != NULL && pred->right != curr){  //we will do this only if there is no link made previously btw pred and curr
                pred  = pred->right;  // get to the rightmost element
            }
            
            if(pred->right == NULL){  // if there is no prev link then make it and move curr to left.
                pred->right = curr;
                curr = curr->left;
            }
            
            else{  // if there was a prev link then remove it to prevent being stuck in loop
                pred->right == NULL;
                cout<<curr->data<<" ";  // print data
                curr = curr->right;   // move to right subtree.
            }
        }

    }
}






void morrisTravrersalPreorder(Node* root){
    Node* curr = root;
    
    while(curr){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            Node* pred = curr->left;
            
            while(pred->right != NULL && pred->right != curr){
                pred  = pred->right;
            }
            
            if(pred->right == NULL){
                pred->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }
            
            else{
                pred->right == NULL;
                
                curr = curr->right;
            }
        }

    }
}




