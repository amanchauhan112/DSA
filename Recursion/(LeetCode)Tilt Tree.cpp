Tilt refer to difference in left and right tree sum
from bottom to up find tilt of each node
and at end return (lefttreesum + righttreesum + root->val)


//     int sumTree(TreeNode*root,int sum)
//         if(!root)
//             return 0;
//         sumtree(root->left);
//         sum+=root->val;
//         sumtree(root->right);
        
//     return sum;
//     }
// int sum=0;
//     int lvlOrder(TreeNode*root,vector<int>&v)
//     {
//         queue<Node*>q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             TreeNode*temp=q.front();
//             q.pop();
//             sum=sumTree(root->left,sum)+sumTree(root->right,sum);
//             // temp->data=sum;
//             v.push_back(sum);
//             if(temp->left) 
//                    q.push(temp->left);
//             if(temp->right)
//                    q.push(temp->right);
//         }
//     }
    
//     int findTilt(TreeNode* root) {
//         vector<int>v;
//         return lvlOrder(root,v);
//         int s=0;
        
//         int n=v.size();
//         for(int i=0;i<n;i++)
//         {
//             s+=v[i];
//         }
        
//         return s;
//     }
    
    int postorder(TreeNode*root,int &ans)
    {
        if(!root)
               return 0; 
        int l=postorder(root->left,ans);
        int r=postorder(root->right,ans);
        
        ans+=abs(l-r);
        
        return l+r+root->val;
        
    }
    
     int findTilt(TreeNode* root) {
         
         if(!root)
               return 0;
         int ans=0;
         postorder(root,ans);
   return ans;
     }
