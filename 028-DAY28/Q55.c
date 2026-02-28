#include <stdio.h>
#include <stdlib.h>

// Structure for Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int n) {
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
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    if(temp != NULL)
        temp->next = head;

    return head;
}

// Function to traverse circular list
void traverseCircularList(struct Node* head) {
    if(head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

// Main Function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);
    traverseCircularList(head);

    return 0;
}
