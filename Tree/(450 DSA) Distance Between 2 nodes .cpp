//We are using LCA approach:
// So basically, first we will  search for common ancestor
// Once We find it we will calculate distance for both nodes from common parent and add them;

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

int dist(Node*root,int find,int d) 
{
    
    
    if(!root)
        return -1;
    
    // if(root->data==a||root->data==b) //I was first confused if data will be on right side or left side of common ancestor
  //But now we are passing the common ancestor.
  
    if(root->data==find)
        return d;
    
    int l=dist(root->left,find,d+1);    //I was doing d+1 in return below;
    int r=dist(root->right,find,d+1);
    
    // return 1+d;
    return max(l,r);        //one of distance will be -1 and other will be real 
                            //We can also write return l!=-1?l:r;
}
   
int findDist(Node* root, int a, int b) {
    // Your code here

    int d=0;
    Node*lca=LCA(root,a,b);
    
    int left=dist(lca,a,d); //Before I was passing lca->left and lca->right
    int right=dist(lca,b,d);
    
    return left+right;
    
}
