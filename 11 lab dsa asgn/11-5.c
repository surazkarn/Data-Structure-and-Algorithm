/*5. First off, some definitions.
An array of length at least 2 having distinct integers is said to be
fantabulous iff the second highest element lies of the highest value.
For example, is fantabulous as the second-highest value lies to the
left of highest value .

For every fantabulous array, we define a
fantabulous pair where denotes the index of the second-highest value
(1-indexed) and denotes the index of the highest value (1-indexed). In
the above array, the fantabulous pair is (3, 5).

Mancunian challenges you to solve the following problem. Given an array, find the
total number of fantabulous pairs over all its subarrays.

The first line contains an integer denoting the length of the array. The
next line contains integers denoting the elements of the array.

Output a single integer which is the answer to the problem.
1 <= N <= 106
1 <= array elements <= 109
Array elements are distinct.*/

#include<stdio.h>
#include<stdlib.h>

typedef long long llint;

llint stack[1000001], top = 0;
llint pops[1000001] = {0}, res[1000001] = {0};

void push(llint num)
{
	stack[top++] = num;
}

llint pop()
{
	llint z = stack[top-1];
	top--;
	return z;
}

llint stk_top()
{
	return stack[top-1];
}

int is_empty()
{
	return top == 0;
}

llint get_int()
{
	int c = gcx();
	llint num = 0;
	while(c >= '0' && c <= '9')
	{
		num = num*10 + c - '0';
		c = gcx();
	}
	return num;
}

void print(llint num)
{
	if(num == 0)
	{
		pcx('0'); pcx('\n'); return;
	}

	char str[30];
	int len = 0;
	while(num)
	{
		str[len++] = '0' + num % 10;
		num/=10;
	}

	while(len--)
	{
		pcx(str[len]);
	}
	pcx('\n');
}

int main()
{
	llint size = get_int();
	// scanf("%lld", &size);1
	llint arr[1000001];
	llint pairs = 0;

	for(llint i = 0; i < size; i++)
	{
		arr[i] = get_int();
		// scanf("%lld", &arr[i]);
		while( !is_empty() && arr[i] > arr[stk_top()])
		{
			llint a = i - stk_top();
			pairs = 1 + pops[stk_top()];
			if(res[a] < pairs)
			{
				res[a] = pairs;
			}
			pops[i] = 1 + pops[stk_top()] + pops[i];
			pop();
			pairs = 0;
		}
		push(i);
	}

	llint sum = 0;
	for(llint i = 0; i < size; i++)
	{
		sum = sum + res[i];
	}
	print(sum);
	return 0;
}