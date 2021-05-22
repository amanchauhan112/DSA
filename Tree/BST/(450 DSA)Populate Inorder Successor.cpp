//Basically in this question we need to connect all nodes in inorder way together by next of p(head/root)
//So we need to take previous node and conncect ir to head node while treaversing.

node*pre=NULL;

void populateNext(struct node* p)
{

// Your code goes here
if(!p)
    return;
    
    populateNext(p->left);
    
    if(pre)
        pre->next=p;
    pre=p;
    populateNext(p->right);
}
