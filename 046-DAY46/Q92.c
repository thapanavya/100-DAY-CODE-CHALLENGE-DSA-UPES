#include <stdlib.h>

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front; // nodes at current level

        // allocate array for this level
        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            level[i] = curr->val;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
    }

    return result;
}
