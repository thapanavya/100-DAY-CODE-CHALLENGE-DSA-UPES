int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // Check if left child exists
    if (root->left != NULL) {
        // If left child is a leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            // Otherwise recurse on left subtree
            sum += sumOfLeftLeaves(root->left);
        }
    }

    // Always recurse on right subtree
    sum += sumOfLeftLeaves(root->right);

    return sum;
}
