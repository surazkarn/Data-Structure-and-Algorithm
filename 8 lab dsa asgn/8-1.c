//1.WAP Write a menu driven program to perform the following operations of a stack using array
//by using suitable user defined functions for each case.
//a) Check if the stack is empty
//b) Display the contents of stack c) Push d) Pop

#include <stdio.h>
#include <string.h>

#define MAX 10
int st[MAX];
int top = -1;
 
void push(int st[], int val);
int pop(int st[]);
void isempty();
void display(int st[]);
void main()
{
    int val, option;

    do
    {
        printf("\n**MAIN MENU");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. ISEMPTY");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option");
        scanf("%d", &option);

        switch (option)
        {

        case 1:

            printf("\n Enter the number to be pushed in stack :");
            scanf("%d", &val);
            push(st, val);
            break;

        case 2:

            val = pop(st);

            if (val != -1)
                printf("\n The deleted element from stack is : %d", val);
            break;

        case 3:

            isempty();
            break;

        case 4:

            display(st);
            break;
        }

    } while (option != 5);
}

void push(int st[], int val)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");

    else
    {
        top++;
        st[top] = val;
    }
}

int pop(int st[])
{
    if (top == -1)
    {
        printf("\nStack underflow");
        return -1;
    }

    else
    {
        top--;
        return (st[top + 1]);
    }
}

void isempty()
{
    if (top == -1)
        printf("the stack is empty\n");
    else
        printf("the stack is not empty\n");
}

void display(int st[])
{
    int i;
    if (top == -1)
    {
        printf("\nStack is empty");
    }

    else
    {
        for (i = top; i >= 0; i--)
            printf("\n%d", st[i]);
    }
}
