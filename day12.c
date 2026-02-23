#include <stdio.h>

int main()
{
    int m, n;
    
    // read rows and columns
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // input matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // check if square matrix
    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    
    // check symmetry
    int symmetric = 1;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }
    
    // output result
    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");
    
    return 0;
}