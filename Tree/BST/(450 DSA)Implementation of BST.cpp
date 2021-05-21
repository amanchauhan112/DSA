BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}
