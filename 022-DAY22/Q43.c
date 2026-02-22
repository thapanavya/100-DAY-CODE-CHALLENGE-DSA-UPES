#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, value, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create Linked List
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Count nodes
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Output count
    printf("%d", count);

    return 0;
}
