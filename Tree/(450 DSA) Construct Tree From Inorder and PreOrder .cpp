// l is 0 h is length of array and preIndex is 0

Node*construct(int in[],int pre[],int l,int h,int&preIndex)
    {
   
            if(l > h)
        return NULL;
        
    Node* root = new Node(pre[preIndex++]);
    
    if(l == h)
        return root;
        
    int i;
    for(i=l;i<=h;i++)
        if(root->data == in[i]) //It is finding Index in Inorder Array 
            break;
            
    if(i <= h)
    {
        root->left = construct(in, pre, l, i-1,preIndex);
        
        root->right = construct(in, pre, i+1, h,preIndex);
    }
    
    return root;
    }
