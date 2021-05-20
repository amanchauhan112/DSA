// Time Complexity: O(N2)

// Auxiliary Space: O(N)

string printDup(Node*root,unordered_map<string,int>&mp,vector<int>&v)
{
    
    string s;
    
    if(!root)
    {
        return ""; 
    }
    
    
    
     s+=to_string(root->data);
    
    string left=printDup(root->left,mp,v);
   
    string right=printDup(root->right,mp,v);
    
    s+=left+right;
  
    if(mp[s]==1)
        v.push_back(root->data);
mp[s]++;
    return s;
        
}

void printAllDups(Node* root)
{
    // Code here
    
    if(!root)
        return;
    
    int flag=0;
        vector<int>v;
    unordered_map<string,int>mp;    //At first i passed int now passing vector
    
    printDup(root,mp,v);
    
   
if(v.size()==0)
    cout<<-1;
else{
     sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}    
 
}
