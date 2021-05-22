/* A O(n^2) program for construction of BST from preorder
* traversal */

// A recursive function to construct Full from pre[].
// preIndex is used to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int low,
						int high, int size)
{
	// Base case
	if (*preIndex >= size || low > high)
		return NULL;

	// The first node in preorder traversal is root. So take
	// the node at preIndex from pre[] and make it root, and
	// increment preIndex
	node* root = newNode(pre[*preIndex]);
	*preIndex = *preIndex + 1;

	// If the current subarry has only one element, no need
	// to recur
	if (low == high)
		return root;

	// Search for the first element greater than root
	int i;
	for (i = low; i <= high; ++i)
		if (pre[i] > root->data)
			break;

	root->left = constructTreeUtil(pre, preIndex, *preIndex,i - 1, size);
	root->right= constructTreeUtil(pre, preIndex, i, high, size);

	return root;
}

// The main function to construct BST from given preorder
// traversal. This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1,size);
}


// -------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------


/* A O(n) program for construction of BST from preorder traversal */


// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key,int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	node* root = NULL;

	// If current element of pre[] is in range, then only it is part of current subtree
	
	if (key > min && key < max) {

		root = newNode(key);
		
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			root->left = constructTreeUtil(pre, preIndex,pre[*preIndex],min, key, size);
		}
		if (*preIndex < size) {
			root->right = constructTreeUtil(pre, preIndex,pre[*preIndex],key, max, size);
		}
	}

	return root;
}

node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0],
							INT_MIN, INT_MAX, size);
}
