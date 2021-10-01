#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a, n, i, j, temp, k;
    printf("Enter the size of array:");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("Enter the kth term:");
    scanf("%d", &k);

    //kth smallest
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (*(a + i) < *(a + j))
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    printf("The kth(%d) smallest element in the array is %d\n", k, *(a + (k - 1)));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (*(a + i) > *(a + j))
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    printf("The kth(%d) largest element in the array is %d", k, *(a + (k - 1)));
    return 0;
}
