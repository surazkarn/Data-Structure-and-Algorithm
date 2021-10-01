#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r, c, **arr, **arr1, i, j, k, temp;
    printf("Enter the number of rows and coulumns: ");
    scanf("%d %d", &r, &c);
    arr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }
    arr1 = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
    {
        arr1[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Enter the matrix elements:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
            arr1[i][j] = arr[i][j];
        }
    }

    //Ascending order of row
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = (j + 1); k < c; k++)
            {
                if (arr[i][j] > arr[i][k])
                {
                    temp = arr[i][k];
                    arr[i][k] = arr[i][j];
                    arr[i][j] = temp;
                }
            }
        }
    }
    printf("Rows of matrix in ascending order:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    //Descending order of column
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            for (k = (j + 1); k < r; k++)
            {
                if (arr1[j][i] < arr1[k][i])
                {
                    temp = arr1[j][i];
                    arr1[j][i] = arr1[k][i];
                    arr1[k][i] = temp;
                }
            }
        }
    }
    printf("Columns of matrix in descending order:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", arr1[i][j]);
        }
        printf("\n");
    }
    return 0;
}
