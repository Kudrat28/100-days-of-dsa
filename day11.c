#include <stdio.h>

int main()
{
    int m, n;
    
    // read rows and columns
    scanf("%d %d", &m, &n);
    
    int A[m][n], B[m][n], Sum[m][n];
    
    // read first matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    
    // read second matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    
    // add matrices
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }
    
    // print result matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", Sum[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}