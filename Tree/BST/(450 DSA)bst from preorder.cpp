/* A O(n^2) program for construction of BST from preorder
* traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

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

	// Use the index of element found in preorder to divide
	// preorder array in two parts. Left subtree and right
	// subtree
	root->left = constructTreeUtil(pre, preIndex, *preIndex,
								i - 1, size);
	root->right
		= constructTreeUtil(pre, preIndex, i, high, size);

	return root;
}

// The main function to construct BST from given preorder
// traversal. This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, 0, size - 1,
							size);
}

// A utility function to print inorder traversal of a Binary
// Tree
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}














/* A O(n) program for construction
of BST from preorder traversal */


// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key,
						int min, int max, int size)
{
	// Base case
	if (*preIndex >= size)
		return NULL;

	node* root = NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max) {
		// Allocate memory for root of this
		// subtree and increment *preIndex
		root = newNode(key);
		*preIndex = *preIndex + 1;

		if (*preIndex < size) {
			// Construct the subtree under root
			// All nodes which are in range
			// {min .. key} will go in left
			// subtree, and first such node
			// will be root of left subtree.
			root->left = constructTreeUtil(pre, preIndex,
										pre[*preIndex],
										min, key, size);
		}
		if (*preIndex < size) {
			// All nodes which are in range
			// {key..max} will go in right
			// subtree, and first such node
			// will be root of right subtree.
			root->right = constructTreeUtil(pre, preIndex,
											pre[*preIndex],
											key, max, size);
		}
	}

	return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size)
{
	int preIndex = 0;
	return constructTreeUtil(pre, &preIndex, pre[0],
							INT_MIN, INT_MAX, size);
}
