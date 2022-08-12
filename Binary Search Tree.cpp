
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
};


Node* insertIntoBST(Node* root, int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    
    
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    
    return root;
}


void takeInput(Node* &root){
    int data ;
    cin>>data;
    
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}


void levelOrderTraversal(Node* root){
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);  // pushed null so that we can detect when to enetr new line
    
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);  // pushed null so that we can detect when to enetr new line
            }
            
        }
        else{
            cout << temp->data <<" ";
            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // inorder traversal follows LNR  
    
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);

}

void preOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // preOrder traversal follows NLR  
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}


void postOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // postorder traversal follows LRN  
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}

int minVal(Node* root){
    if(root == NULL)
        return -1;
    
    Node* temp = root;
    
    while(temp->left != NULL){
        temp = temp->left;
    }
    
    return temp->data;
}

int maxVal(Node* root){
    if(root == NULL)
        return -1;
    
    Node* temp = root;
    
    while(temp->right != NULL){
        temp = temp->right;
    }
    
    return temp->data;
}

Node* deleteFromBST(Node* root , int val){
    // base case
    if(root == NULL)
        return root;
    
    
    // we have to take care of 3 cases: node has 0 child, 1 child , 2 child
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        // 1 child
        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // 2 child  
        if(root->left != NULL && root->right != NULL){
            int maxi = maxVal(root->left);
            root->data = maxi;
            
            root->left = deleteFromBST(root->left,maxi);
            return root;
            // we can do the above by taking min element of right subtree also. both are correct
        }
        
        
    }
    
    // if the node to delete is not root then check for left and right suntree
    else if(root->data > val){
        root->left = deleteFromBST(root->left , val);
    }
    
    else{
        root->right = deleteFromBST(root->right,val);
    }
    
    return root;
}



int main()
{
    Node* root =NULL;
    
    // 50 20 70 10 30 90 110 -1
    cout<<"Enter the data to insert into BST: "<<endl;
    takeInput(root);
    
    cout<<endl<<"Level order traversal"<<endl;
    levelOrderTraversal(root);
    
    cout<<endl<<"Inorder traversal"<<endl;
    inOrderTraversal(root);
    
    cout<<endl<<"Preorder traversal"<<endl;
    preOrderTraversal(root);
    
    cout<<endl<<"postorder traversal"<<endl;
    postOrderTraversal(root);
    
    cout<<endl<<"min value : "<<minVal(root)<<endl;
    cout<<endl<<"max value : "<<maxVal(root)<<endl;
    
    
    // DELETION
    // root = deleteFromBST(root,30);
    // root = deleteFromBST(root,90);
    root = deleteFromBST(root,50);
    
    
    cout<<endl<<"Level order traversal"<<endl;
    levelOrderTraversal(root);
    
    cout<<endl<<"Inorder traversal"<<endl;
    inOrderTraversal(root);
    
    cout<<endl<<"Preorder traversal"<<endl;
    preOrderTraversal(root);
    
    cout<<endl<<"postorder traversal"<<endl;
    postOrderTraversal(root);
    
    cout<<endl<<"min value : "<<minVal(root)<<endl;
    cout<<endl<<"max value : "<<maxVal(root)<<endl;
    
    

    return 0;
}
