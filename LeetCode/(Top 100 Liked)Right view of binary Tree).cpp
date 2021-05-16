  vector<int>print(TreeNode* root,int lvl,int&max_lvl,vector<int>&v)
    {
        if(!root)
            return v;
        if(max_lvl<lvl)       //it will only happen when last node of that lvl
        {
            v.push_back(root->val);
            max_lvl=lvl;
        }
        print(root->right,lvl+1,max_lvl,v);
        print(root->left,lvl+1,max_lvl,v);
        return v;
    }
    vector<int> rightSideView(TreeNode* root) {
        int max_lvl=0;
        vector<int>v;
        return print(root,1,max_lvl,v);
    }
