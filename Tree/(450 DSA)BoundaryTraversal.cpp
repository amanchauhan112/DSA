void inorder(Node* root)
{    if(!root)
return;
    inorder(root->left);
    if(!root->left && !root->right)
    cout<<root->data<<" ";
    inorder(root->right);
}
void printLeaf(Node*root)
{
    if(!root)
        return;
        
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        
        if(!temp->left&&!temp->right)
            cout<<temp->data<<" ";
        
        if(root->left)
            printLeaf(root->left);
        if(root->right)   
            printLeaf(root->right);
    }
    
}
void printLeft(Node*root)
{
    // Node*temp=root;
   
    // while(temp->left)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->left;
    //     while(temp->right&&!temp->left)
    //     {
    //         cout<<temp->data<<" ";
    //         temp=temp->right;
    //     }
    // }
    while(root)
    {

    if(root->left||root->right)
        cout<<root->data<<" ";
    if(root->left)
        root=root->left;
    else
        root=root->right;
}
}

void printRight(Node*root)
{
  stack<int>s;
    while(root)
    {
        
    
    if(root->left||root->right)
        s.push(root->data);
    if(root->right)
        root=root->right;
    else
        root=root->left;
}  
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
      
}
}
vector <int> printBoundary(Node *root)
{
     //Your code here
     
    vector<int>v;
     
    if(!root)
        return v;
    
    cout<<root->data<<" ";
    printLeft(root->left);
    printLeaf(root);    // or inorder(root);
    printRight(root->right);
return v;
}
