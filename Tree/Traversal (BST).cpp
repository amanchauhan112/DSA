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

void levelorder(Node*root)
{
    if(!root)   
        return;
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty())
       {
           Node*temp=q.front();
           cout<<temp->data<<" ";
           if(temp->left)   q.push(temp->left);
           if(temp->right)  q.push(temp->right);
           q.pop();
       }
           
}
    void inorder(Node * head)
    {
        if(!head)
            return;
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }
    void preorder(Node * head)
    {
        if(!head)
            return;
       cout<<head->data<<" ";
        preorder(head->left);
      
        preorder(head->right);
    }
       void postorder(Node * head)
    {
        if(!head)
            return;
     
        postorder(head->left);

        postorder(head->right);
                cout<<head->data<<" ";
    }
    
int main()
{
    Node * root =NULL;
    root=insert(root,12);
    root=insert(root,8);
    root=insert(root,15);
    root=insert(root,13);
    root=insert(root,14);
    root=insert(root,17);
    root=insert(root,20);
    root=insert(root,18);
    root=insert(root,5);
    root=insert(root,7);
    root=insert(root,9);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,11);

    cout<<"Level order Traversal:";
    levelorder(root);
    cout<<"\nDepth traversal:";
    cout<<"\nInorder:";
    inorder(root);
    cout<<"\nPreorder:";
    preorder(root);
    cout<<"\nPostorder:";
    postorder(root);
           
    // return 0;
}

