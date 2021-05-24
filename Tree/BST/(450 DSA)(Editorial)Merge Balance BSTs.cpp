Let there be m elements in first tree and n elements in the other tree. Your merge function should take O(m+n) time.
  
Method 1:Take node one by one of smaller tree and insert it into BST.
  Take all elements of first BST one by one, and insert them into the second BST. Inserting an element to a self balancing BST takes Logn time  where n is size of the BST.
  So time complexity of this method is Log(n) + Log(n+1) … Log(m+n-1).The value of this expression will be between mLogn and mLog(m+n-1) 
  
Method 2:Store Nodes of each tree in array then merge two sortde array and make tree from it.  
  1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
  2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
  3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time
  4) Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.
  
  
  /* This function merges two balanced
BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively */
node* mergeTrees(node *root1, node *root2, int m, int n)
{
    // Store inorder traversal of
    // first tree in an array arr1[]
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);
 
    // Store inorder traversal of second
    // tree in another array arr2[]
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);
 
    // Merge the two sorted array into one
    int *mergedArr = merge(arr1, arr2, m, n);
 
    // Construct a tree from the merged
    // array and return root of the tree
    return sortedArrayToBST (mergedArr, 0, m + n - 1);
}

// A utility unction to merge
// two sorted arrays into one
int *merge(int arr1[], int arr2[], int m, int n)
{
    // mergedArr[] is going to contain result
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;
 
    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaler element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
 
    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++; k++;
    }
 
    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++; k++;
    }
 
    return mergedArr;
}
 
// A helper function that stores inorder
// traversal of a tree rooted with node
void storeInorder(node* node, int inorder[], int *index_ptr)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    storeInorder(node->left, inorder, index_ptr);
 
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* now recur on right child */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A function that constructs Balanced
// Binary Search Tree from a sorted array
See https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/ */
node* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
    return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    node *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
    left child of root */
    root->left = sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
    right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
