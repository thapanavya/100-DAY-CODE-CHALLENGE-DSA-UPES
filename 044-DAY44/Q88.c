#include <stdlib.h>

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;

    if (root == NULL) return result;

    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct TreeNode* curr = stack[top--];

        result[(*returnSize)++] = curr->val;

        // Push right first
        if (curr->right != NULL)
            stack[++top] = curr->right;

        // Push left
        if (curr->left != NULL)
            stack[++top] = curr->left;
    }

    return result;
}
