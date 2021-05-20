// Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes.
//We may assume that either both n1 and n2 are present in the tree or none of them is present.   

//(Parent Node of both)

Node* LCA(Node*root,int n1,int n2)
    {
        
        if(!root)
            return NULL;
          
        if(root->data==n1||root->data==n2)
            return root;
            
        Node* left= LCA(root->left, n1,n2);
        Node* right=LCA(root->right,n1,n2);
        
        if(left&&right)
            return root;
        
        return (right?right:left);    //can take left or right
        
    }
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 

        if(!root)
            return root; 
        
        return LCA(root,n1,n2);       
   
    }
