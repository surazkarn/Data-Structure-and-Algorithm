#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *arr, i, x, y;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    x = *(arr);
    *(arr) = *(arr) * *(arr + 1);
    for (i = 1; i < n - 1; i++)
    {
        y = *(arr + i);
        *(arr + i) = x * *(arr + (i + 1));
        x = y;
    }
    *(arr + (n - 1)) = x * *(arr + (n - 1));
    printf("Output array:\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    return 0;
}
