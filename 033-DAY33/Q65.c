#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

// Function to check precedence
int precedence(char x) {
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {

        // If operand, add to postfix
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If opening bracket
        else if(infix[i] == '(') {
            push(infix[i]);
        }

        // If closing bracket
        else if(infix[i] == ')') {
            while(stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while(top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
