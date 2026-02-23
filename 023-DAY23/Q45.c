#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
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

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node *result = NULL, *temp = NULL;

    while(l1 != NULL && l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if(l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if(result == NULL) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    while(l1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l1->data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
    }

    while(l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l2->data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
        l2 = l2->next;
    }

    return result;
}

void display(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    struct Node* mergedList = mergeLists(list1, list2);

    display(mergedList);

    return 0;
}
