//3.Write a menu driven program to implement circular queue operations such as
//Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using
//static array.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int x)
{
	if(front==-1 && rear==-1){front=0;rear=0;queue[rear]=x;} 
	else if((front==0 && rear==MAX-1)||(front==rear+1)){printf("Circular Queue Overflow.\n");}
	else if(rear==MAX-1){rear=1;queue[rear]=x;}
	else{rear=rear+1;queue[rear]=x;}
}
int dequeue()
{
	if(front==-1){printf("Circular Queue Underflow.\n");}
	int item=queue[front];
	if(front==MAX-1){front=0;return item;}
	else if(front==rear){front=-1;rear=-1;return item;}
	else{front=front+1;return item;}
}
int peek()
{
	if(front==-1){printf("Circular Queue Underflow.\n");}
	else{return queue[front];}
}
void display()
{
	int i=front,j=rear;
	printf("\nThe elements of queue are:\n");
	do{
		printf("%d\t",queue[i]);
		if(i==MAX-1){i=0;}
		else if(i==j){break;}
		else{i++;}
	}while(1);
	printf("\n");
}
void Isempty()
{
	if(front==-1){printf("Queue is empty.\n");}
	else{printf("Queue is not empty.\n");}
}
void Isfull()
{
	if((front==0 && rear==MAX-1)||(front=rear+1)){printf("Queue is full.\n");}
	else{printf("Queue is not full.\n");}
}
int main()
{
	printf("**MENU**\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display elements\n5.Check if empty\n6.Check if full\n0.Exit\n");
	int x,ch;
	do{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter data:");
			scanf("%d",&x);
			enqueue(x);
			break;
			
			case 2:
			printf("The element removed from queue was:%d\n",dequeue());
			break;
			
			case 3:
			printf("The element at the front is: %d\n",peek());
			break;
			
			case 4:
			display();
			break;
			
			case 5:
			Isempty();
			break;
			
			case 6:
			Isfull();
			break;
			
			case 0:
			exit(1);
			
			default:
			printf("Invalid option.\n");
		}
	}while(1);
	return 0;
}