void traverse(Node*root,vector<int>&v)
{
    if(!root)
        return;
    
    traverse(root->left,v);
    v.push_back(root->data);
    traverse(root->right,v);
    
}

void inorder(Node*root,vector<int>&v)
{
    if(!root)
        return;
    
    inorder(root->left,v);
    root->data=v.back();
    v.pop_back();
    inorder(root->right,v);
    
}

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        
        if(!root)
            return NULL;
        
        vector<int>v;
        traverse(root,v);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        inorder(root,v);
        return root;
        
    }
};
