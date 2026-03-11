#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

typedef struct {
    int num;
    int freq;
} Node;

void swap(Node* a, Node* b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Node heap[], int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent].freq > heap[index].freq){
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(Node heap[], int size, int index){
    while(1){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;

        if(left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;

        if(right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if(smallest != index){
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    int freq[RANGE] = {0};

    // Count frequency
    for(int i = 0; i < numsSize; i++)
        freq[nums[i] + OFFSET]++;

    Node* heap = (Node*)malloc(k * sizeof(Node));
    int heapSize = 0;

    for(int i = 0; i < RANGE; i++){
        if(freq[i] > 0){

            Node newNode;
            newNode.num = i - OFFSET;
            newNode.freq = freq[i];

            if(heapSize < k){
                heap[heapSize] = newNode;
                heapifyUp(heap, heapSize);
                heapSize++;
            }
            else if(newNode.freq > heap[0].freq){
                heap[0] = newNode;
                heapifyDown(heap, heapSize, 0);
            }
        }
    }

    int* result = (int*)malloc(k * sizeof(int));

    for(int i = 0; i < k; i++)
        result[i] = heap[i].num;

    *returnSize = k;
    return result;
}
