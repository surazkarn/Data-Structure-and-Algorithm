#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j,*p;
    printf("enter the rows and column: ");
    scanf("%d%d",&m,&n);
    p=(int*)malloc(m*n*sizeof(int));
    printf("enter the element\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",p+n*i+j);
    } printf("given matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t",*(p+n*i+j));
        printf("\n");
    }
    printf("exvhange of 1st to last column ans so on\n");
    for(i=0;i<m;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            printf("%d\t",*(p+n*i+j));
        }
        printf("\n");
    }
    return 0;
}