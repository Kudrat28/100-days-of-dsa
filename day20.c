#include <stdio.h>
#include <stdlib.h>

int countZeroSumSubarrays(int arr[], int n)
{
    int sum = 0;
    int count = 0;

    // hashmap using array (simple version)
    int hash[20001] = {0};

    // shift index to handle negative sums
    int offset = 10000;

    hash[offset] = 1;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(hash[sum + offset] > 0)
            count += hash[sum + offset];

        hash[sum + offset]++;
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

    printf("%d", countZeroSumSubarrays(arr, n));

    return 0;
}