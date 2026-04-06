#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    // If node is a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \    
          4   5  

        Leaf nodes: 4, 5, 3 ? Count = 3
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
