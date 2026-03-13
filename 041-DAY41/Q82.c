#include <stdio.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    
    int freq[26] = {0};
    
    // Count frequencies
    for(int i = 0; i < tasksSize; i++)
        freq[tasks[i] - 'A']++;
    
    int maxFreq = 0;
    
    // Find maximum frequency
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxFreq)
            maxFreq = freq[i];
    
    int maxCount = 0;
    
    // Count tasks with max frequency
    for(int i = 0; i < 26; i++)
        if(freq[i] == maxFreq)
            maxCount++;
    
    int intervals = (maxFreq - 1) * (n + 1) + maxCount;
    
    return tasksSize > intervals ? tasksSize : intervals;
}
