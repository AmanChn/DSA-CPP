// binary tree implementation
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

Node* buildtree(Node* root){
    
    cout<<"Enter data :";
    int data;
    cin>>data;

    root = new Node(data);
    
    //base case
    if(data == -1){  // -1 data means NULL and hence no further child
        return NULL;
    }
    
    //recursive calls to build tree
    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildtree(root->left);
    
    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildtree(root->right);
    
    return root;
}

void buildLevelOrder(Node* &root){
    
    int data;
    cout<<"Enter data for root : ";
    cin >> data;
    
    root = new Node(data);
    
    queue<Node*> q;
    q.push(root);
    
    while(! q.empty()){
        Node* temp = q.front();
        q.pop();
        
        cout<<"Enter left node for "<<temp->data<<" :";
        int leftdata;
        cin>>leftdata;
        
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }
        
        cout<<"Enter right node for "<<temp->data<<" :";
        int rightdata;
        cin>>rightdata;
        
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
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


void morrisTravrersalInorder(Node* root){
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
                curr = curr->left;
            }
            
            else{
                pred->right == NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }

    }
}




int main()
{
    Node* root = NULL;
    
    // root = buildtree(root);
    
    buildLevelOrder(root);
    levelOrderTraversal(root);
    
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"printing the level oredr traversal : "<<endl;
    // levelOrderTraversal(root);
    
    // cout<<"Inorder traversal : ";
    // inOrderTraversal(root);
    // cout<<endl<<"preorder traversal : ";
    // preOrderTraversal(root);
    // cout<<endl<<"postorder traversal : ";
    // postOrderTraversal(root);
    

    return 0;
}
