#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *arr,i;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	scanf("%d",&n);
	int min,max,c=0;
	printf("Enter the two numbers:\n");
	scanf("%d %d",&min,&max);
	for (i=min;i<=max;i++)
	{
		c++;
	}
	printf("The distance between %d and %d is:%d",min, max,c);
	return 0;
}