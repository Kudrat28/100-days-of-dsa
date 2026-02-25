#include <stdio.h>

int main()
{
    int n, k;

    // Input size
    scanf("%d", &n);

    int arr[n], temp[n];

    // Input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Input k
    scanf("%d", &k);

    // Handle k > n
    k = k % n;

    // Copy last k elements to temp
    for(int i = 0; i < k; i++)
        temp[i] = arr[n - k + i];

    // Copy remaining elements
    for(int i = 0; i < n - k; i++)
        temp[k + i] = arr[i];

    // Print result
    for(int i = 0; i < n; i++)
        printf("%d ", temp[i]);

    return 0;
}