void convertToDLL(TreeNode<int>* root , TreeNode<int>* &head){
    if(root == NULL)
        return ;
    
    // make the right subtree into DLL
    convertToDLL(root->right , head );
    
    root->right = head;  // point the root->right to DLL
    if(head != NULL)
        head->left = root;  // point the lead->left to root of tree
    
    head = root;
    // make the left subtree into DLL
    convertToDLL(root->left ,head);
        
}


TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int>* head = NULL;
    convertToDLL(root,head);
	return head;
}