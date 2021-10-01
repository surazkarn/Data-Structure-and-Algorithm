#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *element, i, j, n, next;
    printf("enter the number of times\n");
    scanf("%d", &n);
    element = (int *)malloc(n * sizeof(int));
    printf("enter the element ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (element + i));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(element + i) < *(element + j))
            {
                next = *(element + j);
                break;
            }
        }
        printf("%d ---- %d\n", *(element + i), next);
    }
    return 0;
}
