we can also define static h for doing in same function  

void findKth(Node*root,int k,int &h,int&ans)
    {
        if(!root||k<=h)
            return;
            
        findKth(root->right,k,h,ans); 
        h++;
                if(k==h)
        {
        ans=root->data;
        return;
        }
                
      
        findKth(root->left,k,h,ans);
       

    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        
        int h=0,ans;
        findKth(root,K,h,ans);
        return ans;

    }
