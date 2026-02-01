#include <stdio.h>

int main()
{
    int n, pos, x;
    int i;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n + 1];   // +1 space for new element

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Check valid position
    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return 0;
    }

    // Shift elements to the right
    for(i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    n++;   // Increase size

    // Print updated array
    printf("Updated array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
