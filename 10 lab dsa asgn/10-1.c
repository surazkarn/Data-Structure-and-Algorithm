// 1.WAP to reverse a stack with using extra stack.

#include<stdio.h>
#include<string.h>
# define MAX 10
int st1[MAX];
int st2[MAX];
int top1=-1;
int top2=-1;
void push(int st1[], int val);
int pop(int st1[]);
void display(int st1[]);
void reverse(int st1[], int st2[]);

void main()
{
    int val,option,temp;

 do
 {
        printf("\n**MAIN MENU");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. REVERSE");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            printf("\nEnter the value : ");
            scanf("%d", &val);
            push(st1,val);
            break;

            case 2:
            temp=pop(st1);
            if(temp!=-1)
            {
                printf("%d has been deleted from stack",temp);
            }
            break;
            
            case 3:
                printf("display before reverse: \n");
                display(st1);
                break;
            case 4:
                reverse(st1,st2);
                break;
            default:
                printf("\nINVALID OPTION");
                break;    


        }
 }while(option!=5);
}
void push(int st[], int val)
{
    if(top1==(MAX-1))
    {
       printf("\n Stack Overflow");
    }
    else
    {
        top1++;
        st1[top1]=val;

    }
}
int pop(int st1[])
{
    if(top1==-1)
    {
        printf("Stack Underflow");
        return 0;
    }
    else{
        top1--;
        return(st1[top1+1]);
    }
}
void display(int st1[])
{
    int i;
    if(top1==-1)
    {
        printf("%d\n", st1[i]);
    }
    else{
        for(i=top1;i>-1;i--)
        {
            printf("%d\n", st1[i]);
        }
    }
}
void reverse(int st1[], int st2[])
{
    int i;
    while(top1!=-1)
    {
        top2++;
        st2[top2]=st1[top1];
        top1--;
    }
    if(top2==-1)
    {
        printf("\nStack Underflow");
    }
    else
    {   printf("after reverse:\n");
        for(i=top2;i>-1;i--)
        {
            printf(" %d\n", st2[i]);
        }
    }
}