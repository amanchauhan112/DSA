//We need to print the path which has some equal to k

// This function prints all paths that have sum k
void printKPathUtil(Node *root, vector<int>& path,
                                           int k)
{
    // empty node
    if (!root)
        return;
  
    // add current node to the path
    path.push_back(root->data);
  
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
  
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
  
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];
  
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
  
    // Remove the current element from the path
    path.pop_back();
}
  
// A wrapper over printKPathUtil()
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

//Sample Output for k equals 5

// 3 2 
// 3 1 1 
// 1 3 1 
// 4 1 
// 1 -1 4 1 
// -1 4 2 
// 5 
// 1 -1 5 
