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
bool isSubtreeGreator(Node*root,int data)
{
    if(!root) 
        return true;

       if(data<=root->data&&
       isSubtreeGreator(root->left,data)&&
    isSubtreeGreator(root->right,data))
          return true;
          return false;
}
    

bool isSubtreeLesser(Node*root,int data)
{
    if(!root) 
        return true;
      if(data>=root->data&&
      isSubtreeLesser(root->left,data)&&
    isSubtreeLesser(root->right,data))
          return true;
          return false;
}
    

int isBST(Node*root) //O(N^2)
{
    if(!root)
        return true;
    if(isSubtreeLesser(root->left,root->data)
    &&isSubtreeGreator(root->right,root->data)
    &&isBST(root->left)&&isBST(root->right))
        return true;
    else
        return false;    
 }
        //Efficient Way: O(N)

// bool isBSTree(Node*root,int min,int max)
// {
//     if(!root)
//         return true;
//     if(root->data>min
//     &&root->data<max
//     &&isBSTree(root->left,min,root->data)
//     &&isBSTree(root->right,root->data,max))
//         return true;
//     else
//         return false;
// }

//where min max are INT_MIN && INT_MAX
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

    
    if(isBST(root)==true) 
        cout<<"BST ";
    else
         cout<<"Not BST "; 
   
           
    // return 0;
}
