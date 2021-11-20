//7.WAP to sort the elements inside a stack using only push and pop operation.
//Any number of additional stacks may be used.

#include <stdio.h>
#define MAX 100
int stack[MAX];
int sort[MAX];
int temp[MAX];
int top = -1;
int sort_top = -1;
int temp_top = -1;
void push(int data, int S[], int *t)
{
    if ((*t) == MAX - 1)
    {
        printf("Stack Overflow. \n");
    }
    else
    {
        S[++(*t)] = data;
    }
}
int pop(int s[], int *t)
{
    if (*t = -1)
        return -1;
    else
    {
        return s[(*t)--];
    }
}
void sorting()
{
    sort[++sort_top] = pop(stack, &top);
    while (top != -1)
    {
        while (stack[top] > sort[sort_top] && sort_top >= 0)

        {
            temp[++temp_top] = pop(sort, &sort_top);
        }
        sort[++sort_top] = pop(stack, &top);

        while (temp_top != -1)
        {

            sort[++sort_top] = pop(temp, &temp_top);
        }
    }
}
void display(int stack[], int *t)
{
    for (int i = *t; i >= 0; i--)

        printf("%d\t", stack[i]);
    printf("\n");
}
int main()
{
    int data;

    char c;

    do
    {

        printf("Enter the data: ");

        scanf("%d", data);

        push(data, stack, &top);

        printf("Do you  wish to continue? (y/n): ");
        scanf("%s", &c);
    } while (c != 'n' && c != 'N');

    printf(" The given stack is :");
    display(stack, &top);
    sorting();
    printf("After Sorting:");
    display(sort, &sort_top);
}