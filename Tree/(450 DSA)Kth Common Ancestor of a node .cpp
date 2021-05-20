//Here we are going to use backTracking
//Here node is required node to be find.
//First we check if root->data==node? If not we go to left and right recursively(using or condition)
//Now once we find it we will return until k==0 (We are decrementing k)
//Now when k=0 we can return that node and return NUll;
//Here if we  don't find node we will return some value so we need to chk if our func. returning NULL?
//If not that means we can't find it.


// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;
  
// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node *root, int node , int &k)   //Initially, Node=5 && k=2(As given in Input)
{   
    // Base case
    if (!root)
        return NULL;
      
    if (root->data == node||
       (temp =  kthAncestorDFS(root->left,node,k)) ||
       (temp =  kthAncestorDFS(root->right,node,k)))
    {   
        if (k > 0)        
            k--;
          
        else if (k == 0)
        {
            // print the kth ancestor
            cout<<"Kth ancestor is: "<<root->data;
              
            // return NULL to stop further backtracking
            return NULL;
        }
          
        // return current node to previous call
        return root;
    }
} 
