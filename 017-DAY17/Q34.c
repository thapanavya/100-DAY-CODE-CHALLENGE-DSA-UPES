int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int* nums, int left, int mid, int right) {
    int sum = 0;
    int leftSum = -100000, rightSum = -100000;

    for(int i = mid; i >= left; i--) {
        sum += nums[i];
        if(sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    for(int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if(sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArrayHelper(int* nums, int left, int right) {
    if(left == right)
        return nums[left];

    int mid = (left + right) / 2;

    int leftMax = maxSubArrayHelper(nums, left, mid);
    int rightMax = maxSubArrayHelper(nums, mid+1, right);
    int crossMax = maxCrossingSum(nums, left, mid, right);

    return max(max(leftMax, rightMax), crossMax);
}

int maxSubArray(int* nums, int numsSize) {
    return maxSubArrayHelper(nums, 0, numsSize - 1);
}

