//1.Given an unsorted dynamic array arr and two numbers x and y, find the minimum distance between x and y in arr. The array might also contain duplicates. You may
//assume that both x and y are different and present in arr.

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, *arr,i;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
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