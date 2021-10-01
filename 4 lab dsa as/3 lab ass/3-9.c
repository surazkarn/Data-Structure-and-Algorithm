#include <stdio.h>
int main()
{
    int a[20], i, c = 0, n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
            c++;
    }
    for (i = 0; i < c; i++)
    {
        a[i] = 0;
    }
    for (i = c; i < n; i++)
    {
        a[i] = 1;
    }
    printf("Segregated Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
