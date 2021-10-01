//5.Two brackets are considered to be a matched pair if the an opening bracket
//(i.e., (, [, or { ) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. 
//There are three types of matched pairs of brackets: [], {}, and (). 
//A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. 
//WAP to determine whether the input sequence of brackets is balanced or not. If a string is balanced, 
//it print YES on a new line; otherwise, print NO on a new line.
//Example: Input: {[()]} and Output: YES
//Input: {[(])} and Output: NO

#include <stdio.h>
#include <string.h>

#define MAX 100
int stk[MAX];
int top = -1;

char pop();
void push(char);

void main()
{
    char exp[MAX];
    int temp, i, flag = 1;

    printf("\n Enter an expression");
    gets(exp);

    for (i = 0; i < strlen(exp); i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')

            push(exp[i]);

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {

            if (top == -1)
                flag = 0;

            else
            {
                temp = pop();

                if (exp[i] == ')' && (temp == '{' || temp == '['))
                    flag = 0;

                if (exp[i] == '}' && (temp == '(' || temp == '['))
                    flag = 0;

                if (exp[i] == ']' && (temp == '(' || temp == '{'))
                    flag = 0;
            }
        }
    }

    if (top >= 0)
        flag = 0;

    if (flag == 1)
        printf("\n Yes , string is balanced");

    else
        printf("\n No, string is not balanced");
}

void push(char c)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");

    else
    {
        top++;
        stk[top] = c;
    }
}

char pop()
{
    char c;
    if (top == -1)
        printf("\nStack underflow");

    else
        c = stk[top];
    top--;
    return c;
}