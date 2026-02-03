int missingNum(int arr[], int n) {
    long long sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    long long total = (long long)(n + 1) * (n + 2) / 2;
    return (int)(total - sum);
}

