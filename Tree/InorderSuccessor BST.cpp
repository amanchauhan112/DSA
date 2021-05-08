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

Node*min(Node*head)
{
    if(!head)
        cout<<"Not Found";
    if(!head->left)
        return head;
    else    
        min(head->left);    
}

//Function to find some data in the tree
Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

Node*inordersuccessor(Node*root,int data)
{
    Node*current=Find(root,data);
    
    if(!current)
        return NULL;
        
    if(current->right)
        return min(root->right);
    else
    {
        Node*successor=NULL,*ancestor=root;
        while(ancestor!=current)
        {
            if(current->data<ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
                ancestor=ancestor->right;
        }
    
        return successor;
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

    cout<<"Inorder successor : ";
    Node*temp=inordersuccessor(root,3);
    cout<<temp->data;

}
