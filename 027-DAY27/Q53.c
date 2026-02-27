#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i=0; i<diff; i++)
            p1 = p1->next;
    }
    else {
        for(int i=0; i<diff; i++)
            p2 = p2->next;
    }

    while(p1 != NULL && p2 != NULL) {
        if(p1 == p2)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {

    int n, m, i, val;

    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    for(i=0;i<n;i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if(head1 == NULL)
            head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    for(i=0;i<m;i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if(head2 == NULL)
            head2 = tail2 = newNode;
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Create intersection manually if values match
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            if(temp1->data == temp2->data) {
                tail2->next = temp1;
                goto done;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    done:

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
