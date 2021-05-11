// 897. Increasing Order Search Tree
// 1                       1->2->3->4 5 6 7
// 2     3   ------>>>>>>> 
// 4 5  6 7
  
       TreeNode* increasingBS(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBS(root->left, root);
        root->left = NULL;
        root->right = increasingBS(root->right, tail);
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
    return increasingBS(root);
        
    }
