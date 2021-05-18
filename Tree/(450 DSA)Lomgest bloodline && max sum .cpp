void findSum(Node*root,int & max_sum,int &max_lvl,int sum,int lvl)
{
    if(!root)
        return;
    
    sum+=root->data;
    lvl++;
    
    if(!root->right&&!root->left)
    {
        if(lvl>max_lvl)
        {
            max_lvl=lvl;
            max_sum=sum;
        }
        
        if(lvl==max_lvl&&sum>max_sum)   //This tells us that we are at leaf node
            max_sum=sum;
         
    }
    
    findSum(root->left,max_sum,max_lvl,sum,lvl);    
    findSum(root->right,max_sum,max_lvl,sum,lvl); 
    
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	
	int max_sum=0,max_lvl=0;
	findSum(root,max_sum,max_lvl,0,0);
	return max_sum;
}
