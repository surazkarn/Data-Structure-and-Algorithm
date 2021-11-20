/*6.Alice is rearranging her library. She takes the innermost shelf and
reverses the order of books. She breaks the walls of the shelf. In the
end, there will be only books and no shelf walls. Print the order of
books.
Opening and closing walls of shelves are shown by '/' and '\'  respectively whereas books are represented 
by lower case alphabets.
The first line contains string displaying her library.
Print only one string displaying Alice's library after rearrangement.
The first character of the string is '' and the last character of the string is '' indicating
outermost walls of the shelf.*/

#include<stdio.h>
#include<string.h>
typedef struct stack
{
	char A[1000];
	int top;
}stack;
void arranging(char *s, int n, stack *p)
{
	int i,j,k;
	char temp[1000];
	for(i=0; i<n; ++i)
	{
		if(s[i] == '\\')
		{
			k = 0;
			while(p->A[p->top] != '/')
				temp[k++] = p->A[p->top--];
			--p->top;
			j=0;
			while(j<k)
				p->A[++p->top] = temp[j++];
		}
		else
			p->A[++p->top] = s[i];
	}
	for(i=0;i<=p->top;i++)
	{
		printf("%c",p->A[i]);
	}
}
int main(void)
{
	stack s1;
	s1.top = -1;
	char S[1000];
	printf("Enter a String\n");
	scanf("%s", S);
	arranging(S,strlen(S),&s1);
	return 0;
}