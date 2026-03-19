#include <stdio.h>
#include <stdlib.h>

#define MAX 50000

typedef struct {
    int maxHeap[MAX]; // left (max heap)
    int minHeap[MAX]; // right (min heap)
    int maxSize;
    int minSize;
} MedianFinder;

// ---------- MAX HEAP ----------
void maxHeapInsert(MedianFinder* obj, int val) {
    int i = obj->maxSize++;
    while (i > 0 && obj->maxHeap[(i - 1) / 2] < val) {
        obj->maxHeap[i] = obj->maxHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    obj->maxHeap[i] = val;
}

int maxHeapRemove(MedianFinder* obj) {
    int root = obj->maxHeap[0];
    int last = obj->maxHeap[--obj->maxSize];

    int i = 0, child;
    while (2 * i + 1 < obj->maxSize) {
        child = 2 * i + 1;
        if (child + 1 < obj->maxSize && obj->maxHeap[child + 1] > obj->maxHeap[child])
            child++;

        if (last >= obj->maxHeap[child]) break;

        obj->maxHeap[i] = obj->maxHeap[child];
        i = child;
    }
    obj->maxHeap[i] = last;
    return root;
}

// ---------- MIN HEAP ----------
void minHeapInsert(MedianFinder* obj, int val) {
    int i = obj->minSize++;
    while (i > 0 && obj->minHeap[(i - 1) / 2] > val) {
        obj->minHeap[i] = obj->minHeap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    obj->minHeap[i] = val;
}

int minHeapRemove(MedianFinder* obj) {
    int root = obj->minHeap[0];
    int last = obj->minHeap[--obj->minSize];

    int i = 0, child;
    while (2 * i + 1 < obj->minSize) {
        child = 2 * i + 1;
        if (child + 1 < obj->minSize && obj->minHeap[child + 1] < obj->minHeap[child])
            child++;

        if (last <= obj->minHeap[child]) break;

        obj->minHeap[i] = obj->minHeap[child];
        i = child;
    }
    obj->minHeap[i] = last;
    return root;
}

// ---------- MAIN FUNCTIONS ----------
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // Step 1: Insert into max heap
    if (obj->maxSize == 0 || num <= obj->maxHeap[0])
        maxHeapInsert(obj, num);
    else
        minHeapInsert(obj, num);

    // Step 2: Balance heaps
    if (obj->maxSize > obj->minSize + 1) {
        minHeapInsert(obj, maxHeapRemove(obj));
    } else if (obj->minSize > obj->maxSize) {
        maxHeapInsert(obj, minHeapRemove(obj));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize == obj->minSize) {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    } else {
        return obj->maxHeap[0];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
