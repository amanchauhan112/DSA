//Only nodes of left and right can be swapped 

  bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
    
    if(!root1&&!root2)
        return true;
            if(!root1||!root2)
        return false;
    if(root1->data!=root2->data)    
        return false;
    
    return (isIsomorphic(root1->left,root2->left)&&
    isIsomorphic(root1->right,root2->right)||
    isIsomorphic(root1->left,root2->right)&&
    isIsomorphic(root1->right,root2->left));

    }
