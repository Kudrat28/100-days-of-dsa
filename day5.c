#include <stdio.h>

int main()
{
    int p, q, i = 0, j = 0, k = 0;

    // Input size of first log
    scanf("%d", &p);
    int log1[p];

    // Input first log
    for(i = 0; i < p; i++)
    {
        scanf("%d", &log1[i]);
    }

    // Input size of second log
    scanf("%d", &q);
    int log2[q];

    // Input second log
    for(j = 0; j < q; j++)
    {
        scanf("%d", &log2[j]);
    }

    int merged[p + q];
    i = 0;
    j = 0;

    // Merge process
    while(i < p && j < q)
    {
        if(log1[i] <= log2[j])
        {
            merged[k++] = log1[i++];
        }
        else
        {
            merged[k++] = log2[j++];
        }
    }

    // Copy remaining elements
    while(i < p)
    {
        merged[k++] = log1[i++];
    }

    while(j < q)
    {
        merged[k++] = log2[j++];
    }

    // Print merged log
    for(i = 0; i < p + q; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}
