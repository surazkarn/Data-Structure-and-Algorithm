#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,*b,n,c=0,e=0,o=0,i;
	printf("Enter the size of array;");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for (i=0;i<n;i++)
	{
		*(b+i)=*(a+i);
	}
	for (i=0;i<n;i++)
	{
		if (*(a+i)%2==0)
		c++;
	}
	for (i=0;i<n;i++)
	{
		if (*(b+i)%2==0)
		{
			*(a+e)=*(b+i);
			e++;
		}
		else
		{
			*(a+(c+o))=*(b+i);
			o++;
		}
	}
	printf("Segregated Array:\n");
	for (i=0;i<n;i++)
	{
		printf("%d ",*(a+i));
	}
	return 0;
}
