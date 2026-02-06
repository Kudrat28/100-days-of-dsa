#include <stdio.h>

int main()
{
    int n, i, k;
    int comparisons = 0;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    // Linear Search
    for(i = 0; i < n; i++)
    {
        comparisons++;  // Count each comparison
        
        if(arr[i] == k)
        {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d", comparisons);
            return 0;
        }
    }

    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d", comparisons);

    return 0;
}
