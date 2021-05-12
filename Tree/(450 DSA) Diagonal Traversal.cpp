
vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>v;
   if(!root)
    return v;
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty())
   {
       Node*temp=q.front();
       while(temp)
      {
        cout<<temp->data<<" ";
      
       if(temp->left)
            q.push(temp->left);
       temp=temp->right;
      }
       q.pop();
   }
}

For Input:
8 3 10 1 6 N 14 N N 4 7 13
your output is: 
8 10 14 3 6 7 13 1 4 
