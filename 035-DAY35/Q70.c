#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Simple stack implementation
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void pushStack(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

int popStack(Stack* stack) {
    return stack->data[stack->top--];
}

int peekStack(Stack* stack) {
    return stack->data[stack->top];
}

// Queue using two stacks
typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->inStack = createStack(100);   // capacity enough for constraints
    q->outStack = createStack(100);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->outStack)) {
        while (!isEmpty(obj->inStack)) {
            pushStack(obj->outStack, popStack(obj->inStack));
        }
    }
    return popStack(obj->outStack);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->outStack)) {
        while (!isEmpty(obj->inStack)) {
            pushStack(obj->outStack, popStack(obj->inStack));
        }
    }
    return peekStack(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->inStack) && isEmpty(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    free(obj->inStack->data);
    free(obj->inStack);
    free(obj->outStack->data);
    free(obj->outStack);
    free(obj);
}

