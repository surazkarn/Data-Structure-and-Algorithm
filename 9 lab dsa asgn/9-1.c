//1.Write a menu driven program to implement queue operations such as Enqueue,
//Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int rear = -1;
int front =-1;

void enqueue(int x);
int dequeue();
int peek();
void display();
int isFull();
int isEmpty();

void enqueue(int x)
{
        if(rear==MAX-1)
        {
                printf("\nQueue Overflow...\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear=rear+1;
        queue[rear]=x ;
}

int dequeue()
{
        int x;
        if(front==-1 || front==rear+1)
        {
                printf("\nQueue Underflow...\n");
                exit(1);
        }
        x=queue[front];
        front=front+1;
        return x;
}

int peek()
{
        if(front==-1 || front==rear+1)
        {
                printf("\nQueue Underflow...\n");
                exit(1);
        }
        return queue[front];
}

int isEmpty()
{
        if(front==-1 || front==rear+1){
        	 printf("\nQueue is empty...\n");
                return 1;
        }
        else{
        	 printf("\nQueue is not empty...\n");
                return 0;
       }
}

int isFull()
{
        if(rear==MAX-1){
        	printf("\nQueue is full...\n");
                return 1;
        }
        else{
        	printf("\nQueue is not full...\n");
                return 0;
        }
}

void display()
{
        int i;
        if (front==-1 || front==rear+1)
        {
                printf("\nQueue is empty...\n");
                return;
        }
        printf("\nQueue is :\n");
        for(i=front; i <= rear; i++)
                printf("%d  ",queue[i]);
        printf("\n");
}

int main()
{
        int choice,x;


                printf("\n1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Peek\n");
                printf("4. Display \n");
                printf("5. Check if empty.\n");
                printf("6. Check if full. \n");
                printf("0. Quit\n");
                while(1){
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("Enter the element for queue : ");
                        scanf("%d",&x);
                       enqueue(x);
                        break;
                case 2:
                        x=dequeue();
                        printf("Deleted element is  %d.",x);
                        break;
                case 3:
                        printf("\nElement at the front is %d.",peek());
                        break;
                case 4:
                        display();
                        break;
                       
                case 5:
                	isEmpty();
                	break;
                case 6:
                	isFull();
                	break;
                case 0:
                        exit(1);
                default:
                        printf("\nWrong choice!!!\n");
                }
        }
        return 0;
}
