#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    int matrix[n][n];
    
    // input matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int isIdentity = 1;
    
    // check identity matrix condition
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                // diagonal elements must be 1
                if(matrix[i][j] != 1)
                {
                    isIdentity = 0;
                    break;
                }
            }
            else
            {
                // non-diagonal elements must be 0
                if(matrix[i][j] != 0)
                {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }
    
    // output result
    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");
    
    return 0;
}