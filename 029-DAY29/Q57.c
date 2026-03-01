#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create Linked List
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate Right by k
struct Node* rotateRight(struct Node* head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int n = 1;

    // Find length & last node
    while(temp->next) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    k = k % n;
    int steps = n - k;

    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print List
void printList(struct Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
