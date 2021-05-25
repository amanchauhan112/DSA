// We cant add any further node if left is 1 or root->data-1 or root->data+1 is found again

void traverse(Node*root,int &b,int l,int r)
{
    if(!root)
        return;
    
    if(r==1||l==r)
        b=1;  
    
    traverse(root->left,b,l,root->data-1);
    traverse(root->right,b,root->data+1,r);
    
}

bool isDeadEnd(Node *root)
{
    //Your code here
    int b=0;
    traverse(root,b,INT_MIN,INT_MAX);
    return b;
}
