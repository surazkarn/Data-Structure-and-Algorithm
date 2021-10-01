#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, *temp;
    printf("enter the bits of an array\t->\t");
    scanf("%d", &n);
    temp = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (temp + i));
    }
    for (i = 0; i < n; i++)
    {
        if (*(temp + i) % 2 == 0)
            printf("%d\t", *(temp + i));
    }
    for (i = 0; i < n; i++)
    {
        if (*(temp + i) % 2 != 0)
            printf("%d\t", *(temp + i));
    }
}