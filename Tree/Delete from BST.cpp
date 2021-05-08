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

void inorder(Node * head)
{
    if(!head)
        return;
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

Node*min(Node*head)
{
    if(!head)
        cout<<"Not Found";
    if(!head->left)
        return head;
    else    
        min(head->left);    
}

Node*deleteFromBST(Node*root,int data)
{
    if(!root)
        return root;
    else if(root->data>data) root->left=deleteFromBST(root->left,data);  
    else if(root->data<data) root->right=deleteFromBST(root->right,data);
    else    //matched
    {
        // 0 child
        
        if(!root->left&&!root->right)
            {
                delete root;
                root=NULL;
                return root;
            }
        
        // 1 child
        
        else if(root->left==NULL)
        {
            Node*temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(!root->right)
        {
            Node*temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        
        // 2 child
        
        else{
            Node*temp=min(root->right);
            root->data=temp->data;
            root->right=deleteFromBST(root->right,temp->data);
    
        }
        
        
    }
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

    cout<<"Inorder:";
    inorder(root);
    deleteFromBST(root,12);
    cout<<"\nInorder:";
    inorder(root);

}
