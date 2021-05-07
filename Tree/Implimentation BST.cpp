#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node*right;
};

Node*GetnewNode(int data)
{
    Node*newNode=new Node();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
}

Node* insert(Node*head,int data)
{
    if(head==NULL)
    {
        head=GetnewNode(data);
    }
    else if(data<=head->data)
    {
        
        head->left=insert(head->left,data);
    }
    else
    {
            
        head->right=insert(head->right,data);
    }
    return head;
}

bool search(Node*head,int data)
{
    if(!head)
        return false;
    else if(head->data==data)   return true;
    else if(head->data<=data)
        search(head->left,data);    
    else
        search(head->left,data);    
}

Node*min(Node*head)
{
    if(!head)
        cout<<"Not Found";
    if(!head->left)
        cout<<head->data;
    else    
        min(head->left);    
}

Node*max(Node*head)
{
    if(!head)
        cout<<"Not Found";
    if(!head->right)
        cout<<head->data;
    else    
        max(head->right);    
}

int height(Node*head)
{
    if(!head)
        return -1;
    else
        return max(height(head->left),height(head->right))+1;
        
        
}
    

int main()
{
    Node * root =NULL;
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,15);
    
    if(search(root,15)==true)
        cout<<"Found\n";
    else
      cout<<"Not Found\n";
        cout<<"Minimum:";
        min(root);
          cout<<"\nMaximum:";
           max(root);
           cout<<"\nMaximum height:";
           cout<<height(root);  
    // return 0;
}
