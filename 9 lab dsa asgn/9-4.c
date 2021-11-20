//4.Write a menu driven program to implement Deques (both
//Input-restricted and Output-restricted) operations such as Enqueue,
//Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
int deque[MAX];
int left = -1, right = -1;
void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);
int peek(void);
void isempty();
void isfull();
int main()
{
    int option;
    printf("\n *MENU for Double Ended Queue uisng Array*");
    printf("\n 1.Input restricted deque");
    printf("\n 2.Output restricted deque");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        input_deque();
        break;
    case 2:
        output_deque();
        break;
    }
    return 0;
}
void input_deque()
{
    int option;
    do
    {
        printf("\n INPUT RESTRICTED DEQUEUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Delete from left");
        printf("\n 3.Delete from right");
        printf("\n 4.Display");
        printf("\n 5.Peek");
        printf("\n 6.ISEMPTY");
        printf("\n 7.ISFULL");
        printf("\n 8.Quit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display();
            break;
        case 5:
            peek();
            break;
        case 6:
            isempty();
            break;
        case 7:
            isfull();
            break;
        }
    } while (option != 8);
}
void output_deque()
{
    int option;
    do
    {
        printf("OUTPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from left");
        printf("\n 4.Display");
        printf("\n 5.PEEK");
        printf("\n 6.ISEMPTY");
        printf("\n 7.ISFULL");
        printf("\n 8.Quit");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display();
            break;
        case 5:
            peek();
            break;
        case 6:
            isempty();
            break;
        case 7:
            isfull();
            break;
        }
    } while (option != 8);
}
void insert_right()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\n OVERFLOW");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (right == MAX - 1)
            right = 0;
        else
            right = right + 1;
    }
    deque[right] = val;
}
void insert_left()
{
    int val;
    printf("\n Enter the value to be added:");
    scanf("%d", &val);
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf("\n Overflow");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else
    {
        if (left == 0)
            left = MAX - 1;
        else
            left = left - 1;
    }
    deque[left] = val;
}
void delete_left()
{
    if (left == -1)
    {
        printf("\n UNDERFLOW");
        return;
    }
    printf("\n The deleted element is : %d", deque[left]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (left == MAX - 1)
            left = 0;
        else
            left = left + 1;
    }
}
void delete_right()
{
    if (left == -1)
    {
        printf("\n UNDERFLOW");
        return;
    }
    printf("\n The element deleted is : %d", deque[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (right == 0)
            right = MAX - 1;
        else
            right = right - 1;
    }
}
void display()
{
    int front = left, rear = right;
    if (front == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return;
    }
    printf("\n The elements of the queue are : ");
    if (front <= rear)
    {
        while (front <= rear)
        {
            printf("%d\t", deque[front]);
            front++;
        }
    }
    else
    {
        while (front <= MAX - 1)
        {
            printf("%d\t", deque[front]);
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            printf("%d\t", deque[front]);
            front++;
        }
    }
    printf("\n");
}
void isempty()
{
     if(left==-1||left>right)
         printf("\nqueue is empty");
     else
        printf("\nqueue is not empty");
}
void isfull()
{
    if(right==MAX)
        printf("\nqueue is full");
    else   
        printf("\nqueue is not full");
}/* 
int peek()
{
  if(left==-1 || left>right)
  {
   printf("\nQueue is empty");
   return -1;
  }   
  else
    return(deque[left]); 
} */


int peek()
{
        if(left==-1 || left==right+1)
        {
                printf("\nQueue Underflow...\n");
                exit(1);
        }
        return deque[left];
}