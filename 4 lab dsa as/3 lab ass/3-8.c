#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int i,j,*arr,num=0,fre=1,n;
	printf("Enter the range : ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);

		(arr[i]>num)?num=arr[i],fre=1:(arr[i]==num)?fre++:fre;
	}
	
	printf ("\nThe largest number is %d having %d occurrence.",num,fre);
	}