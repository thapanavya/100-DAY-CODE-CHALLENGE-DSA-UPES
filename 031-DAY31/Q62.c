#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // Stack using array
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        
        char ch = s[i];
        
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // If closing bracket
        else {
            // If stack is empty ? invalid
            if (top == -1)
                return false;
            
            char topChar = stack[top--];
            
            // Check matching pair
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    // If stack empty ? valid
    return (top == -1);
}
