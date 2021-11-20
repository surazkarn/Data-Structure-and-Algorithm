//2.Write a menu driven program to implement queue operations such as Enqueue,
//Dequeue, Peek, Display of elements, IsEmpty using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int peek();
void enqueue(int x);
void dequeue();
void empty();
void display();
void create();

int count = 0;

void create()
{
    front = rear = NULL;
}

void enqueue(int x)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->data = x;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->data = x;
        temp->ptr = NULL;

        rear = temp;
    }
    count++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("\nQueue is empty...\n");
        return;
    }
    printf("\nQueue is :\n\n");

    while (front1 != rear)
    {
        printf("%d  ", front1->data);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        {printf("%d  ", front1->data);}
         printf("\n");
}

void dequeue()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\nQueue Underflow...\n");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\nDeleted value : %d", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Deleted value : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

int peek()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}

void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\nQueue is empty...\n");
    else
       printf("\nQueue is not empty...\n");
}

void main()
{
    int no, ch, e;

    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Empty\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    create();
    while(1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the element for queue : ");
            scanf("%d",&no);
            enqueue(no);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            e = peek();
            if (e != 0)
                printf("\nFront element : %d", e);
            else
                printf("\nQueue is empty...");
            break;
        case 4:
            empty();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("\nWrong choice!!!\n");
            break;
        }
    }
}
