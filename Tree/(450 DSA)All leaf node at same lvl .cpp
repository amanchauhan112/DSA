//CHK depth same or not  for both left and right.

int depth(Node*root,bool&ans)
    {
        if(!root)
            return 0;
        if(!root->right&&!root->left)
            return 1;
            
        int left=depth(root->left,ans);
        int right=depth(root->right,ans);
        
        if(left&&right&&left!=right)
            ans=false;
            
        return (max(right,left)+1);    
    }
    
    bool check(Node *root)
    {
        //Your code here
        
        bool ans=true;
        
        depth(root,ans);
        
        return ans;
    }
