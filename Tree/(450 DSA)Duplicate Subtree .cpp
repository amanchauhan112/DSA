string check(Node*root,unordered_map<string,int>&mp)
{
    string s="";
    
    if(!root)
    {
        s+="$";
        return s;
    }

    s+=root->data;
    
    string left=check(root->left,mp);
   
    string right=check(root->right,mp);
    s+=left+right;
    mp[s]++;
    
    return s;
    
}

bool dupSub(Node *root)
{
     //your code here
     
     unordered_map<string,int>mp;
     check(root,mp);
     
     for(auto i:mp)
        if(i.second>1&&i.first.length()>3)    //For leaf node (root->data)$$ ->so it will be same so length of 2nd should be more than 3
            return 1;
    
    return 0;        
     
     
}
