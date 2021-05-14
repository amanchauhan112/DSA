// Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left 
// and right sub trees of the original tree. The values of leaf nodes are changed to 0.

  
    int postorder(Node*node)
    {
        if(!node)
            return 0;
        
        int d=node->data;
            
        int lsum=postorder(node->left);
        int rsum=postorder(node->right);
        
        node->data=lsum+rsum;
        return d+lsum+rsum;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        
        postorder(node);
    
    }
    
//  OR

public void toSumTree(Tree root){
if(root == null) return;
root.data = (root.left == null ? 0 : root.left.data) + (root.right == null ? 0 : root.right.data);
toSumTree(root.left);
toSumTree(root.right);
root.data += (root.left == null ? 0 : root.left.data) + (root.right == null ? 0 : root.right.data);
}
