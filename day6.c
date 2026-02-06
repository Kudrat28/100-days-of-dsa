#include <stdio.h>

int main()
{
    int n, i;

    // Input size
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    int arr[n];

    // Input elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Two-pointer approach
    int j = 0;  // Points to last unique element

    for(i = 1; i < n; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    // Print unique elements
    for(i = 0; i <= j; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
