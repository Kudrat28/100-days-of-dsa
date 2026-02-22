#include <stdio.h>
#include <string.h>

int main()
{
    char code[100];
    int i, length;

    // input string
    scanf("%s", code);

    // find length
    length = strlen(code);

    // print in reverse order
    for(i = length - 1; i >= 0; i--)
    {
        printf("%c", code[i]);
    }

    return 0;
}