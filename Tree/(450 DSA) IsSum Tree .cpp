//Here the trick is that if node is leaf then its same as value 
//If not leaf then it will be 2*ls+2*rs 

bool isLeaf(Node* root)
    {
    return (root->left==NULL&&root->right==NULL);
    }
 
    bool isSumTree(Node* root)
    {
         // Your code here
         
        if(!root||isLeaf(root))
            return 1;
            
        int ls,rs;
        
        if(isSumTree(root->left)&&isSumTree(root->right))
        {
            if(!root->left)
                ls=0;
            else if(isLeaf(root->left))
                ls=root->left->data;
            else
                ls=2*root->left->data;
           
            if(!root->right)
                rs=0;
            else if(isLeaf(root->right))
                rs=root->right->data;
            else
                rs=2*root->right->data;
            
            return (root->data==ls+rs);    
        }
   
        return 0;
    }



//or 
//simply calculate sum and chk if sumTree or not

int sum(struct node *root)
{
    if (root == NULL)
        return 0;
    
    return sum(root->left) + root->data +
           sum(root->right);
}

// Returns 1 if sum property holds for
// the given node and both of its children 
int isSumTree(struct node* node)
{
    int ls, rs;

    // If node is NULL or it's a leaf
    // node then return true 
    if (node == NULL ||
       (node->left == NULL && 
        node->right == NULL))
        return 1;

   // Get sum of nodes in left and
   // right subtrees 
   ls = sum(node->left);
   rs = sum(node->right);

   // If the node and both of its 
   // children satisfy the property 
   // return 1 else 0
    if ((node->data == ls + rs) &&
          isSumTree(node->left) &&
          isSumTree(node->right))
        return 1;

   return 0;
}
