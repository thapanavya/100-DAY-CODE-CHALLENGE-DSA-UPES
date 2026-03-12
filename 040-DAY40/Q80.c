#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    int *result = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(temperaturesSize * sizeof(int));

    int top = -1;

    for(int i = 0; i < temperaturesSize; i++){

        while(top >= 0 && temperatures[i] > temperatures[stack[top]]){

            int index = stack[top--];
            result[index] = i - index;
        }

        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return result;
}
