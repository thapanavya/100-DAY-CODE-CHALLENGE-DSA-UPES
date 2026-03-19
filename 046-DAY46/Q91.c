#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue
Node* queue[100];
int front = 0, rear = 0;

void enqueue(Node* node) {
    queue[rear++] = node;
}

Node* dequeue() {
    return queue[front++];
}

// Build tree
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        Node* curr = q[f++];
        printf("%d ", curr->data);

        if (curr->left) q[r++] = curr->left;
        if (curr->right) q[r++] = curr->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
