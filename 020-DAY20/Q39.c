#include <stdio.h>

int countZeroSumSubarrays(int arr[], int n)
{
    int count = 0;
    int sum = 0;

    int freq[1000] = {0}; 

    int offset = 500;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum == 0)
            count++;

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = countZeroSumSubarrays(arr, n);

    printf("%d", result);

    return 0;
}
