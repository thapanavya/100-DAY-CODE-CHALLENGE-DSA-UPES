#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calculate(char* s) {
    int len = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int num = 0;
    char op = '+';

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ') || i == len - 1) {
            if (op == '+') {
                stack[++top] = num;
            } else if (op == '-') {
                stack[++top] = -num;
            } else if (op == '*') {
                stack[top] = stack[top] * num;
            } else if (op == '/') {
                // truncate toward zero
                stack[top] = stack[top] / num;
            }
            op = ch;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }

    free(stack);
    return result;
}

