int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = 0;
    
    int maxSum = nums[0];
    int curMax = 0;
    
    int minSum = nums[0];
    int curMin = 0;
    
    for(int i = 0; i < numsSize; i++) {
        
        totalSum += nums[i];
        
        curMax = (curMax > 0 ? curMax : 0) + nums[i];
        maxSum = (maxSum > curMax) ? maxSum : curMax;
        
        curMin = (curMin < 0 ? curMin : 0) + nums[i];
        minSum = (minSum < curMin) ? minSum : curMin;
    }
    
    if(maxSum < 0)
        return maxSum;
    
    return (maxSum > (totalSum - minSum)) ? maxSum : (totalSum - minSum);
}

