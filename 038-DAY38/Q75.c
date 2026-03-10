#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

/* Deque structure */
typedef struct Deque
{
    Node* front;
    Node* rear;
    int size;
}Deque;


/* Create Deque */
Deque* createDeque()
{
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
    return dq;
}


/* Check empty */
int empty(Deque* dq)
{
    return dq->size == 0;
}


/* Size */
int getSize(Deque* dq)
{
    return dq->size;
}


/* push_front */
void push_front(Deque* dq, int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = dq->front;

    if(empty(dq))
        dq->rear = temp;
    else
        dq->front->prev = temp;

    dq->front = temp;
    dq->size++;
}


/* push_back */
void push_back(Deque* dq, int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = dq->rear;

    if(empty(dq))
        dq->front = temp;
    else
        dq->rear->next = temp;

    dq->rear = temp;
    dq->size++;
}


/* pop_front */
void pop_front(Deque* dq)
{
    if(empty(dq))
    {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if(dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}


/* pop_back */
void pop_back(Deque* dq)
{
    if(empty(dq))
    {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if(dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}


/* front element */
int front(Deque* dq)
{
    if(empty(dq))
    {
        printf("Deque is empty\n");
        return -1;
    }

    return dq->front->data;
}


/* back element */
int back(Deque* dq)
{
    if(empty(dq))
    {
        printf("Deque is empty\n");
        return -1;
    }

    return dq->rear->data;
}


/* clear deque */
void clear(Deque* dq)
{
    while(!empty(dq))
        pop_front(dq);
}


/* display deque */
void display(Deque* dq)
{
    Node* temp = dq->front;

    printf("Deque: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


/* reverse deque */
void reverse(Deque* dq)
{
    Node* current = dq->front;
    Node* temp = NULL;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = dq->front;
    dq->front = dq->rear;
    dq->rear = temp;
}


/* main function */
int main()
{
    Deque* dq = createDeque();

    push_back(dq,10);
    push_back(dq,20);
    push_front(dq,5);
    push_front(dq,1);

    display(dq);

    printf("Front element: %d\n", front(dq));
    printf("Rear element: %d\n", back(dq));

    pop_front(dq);
    pop_back(dq);

    display(dq);

    printf("Size: %d\n", getSize(dq));

    reverse(dq);
    printf("After reverse:\n");
    display(dq);

    clear(dq);
    printf("Deque cleared\n");

    display(dq);

    return 0;
}
