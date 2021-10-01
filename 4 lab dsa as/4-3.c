#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp, *nextnode;
int value, count = 0, cprime = 0;
struct node create()
{
    printf("enter '0'to stop storing value:\n");
    printf("enter the value you want to store:");
    scanf("%d", &value);
    while (value)
    {
        nextnode = (struct node *)malloc(sizeof(struct node));
        nextnode->data = value;
        nextnode->next = NULL;
        if (head == NULL)
        {
            head = nextnode;
            temp = nextnode;
        }
        else
        {
            temp->next = nextnode;
            temp = nextnode;
        }
        printf("enter the value you want to store:");
        scanf("%d", &value);
    }
    if (head == NULL)
    {
        printf("the link list is empty:\n");
    }
    else
        printf("the link list is not empty:\n");
}
struct node display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
struct node addinbegening()
{
    printf("enter the value you want to add at the begening:");
    scanf("%d", &value);
    nextnode = (struct node *)malloc(sizeof(struct node));
    nextnode->data = value;
    nextnode->next = head;
    head = nextnode;
}
struct node addatend()
{
    nextnode = (struct node *)malloc(sizeof(struct node));
    
    printf("enter the value you want to insert at the end:");
    scanf("%d", &value);
    nextnode->data = value;
    nextnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nextnode;
}
struct node countnum()
{
    temp = head;
    head = temp;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    printf("there are %d no of element present in link list", count);
}
struct node deleteatbegening()
{
    temp = head;
    head = head->next;
}
struct node deleteattheend()
{
    struct node *prev;
    temp = head;
    head = temp;
    while (temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    temp = prev;
    temp->next = NULL;
}
struct node ceheckodd_even()
{
    temp = head;
    int codd = 0, ceven = 0;
    while (temp != 0)
    {
        if (temp->data % 2 == 0)
        {
            ceven++;
        }
        else
        {
            codd++;
        }
        temp = temp->next;
    }
    printf("there are %d number of odd numbers in link list\n", codd);
    printf("there are %d number of even numbers in link list\n", ceven);
}
struct node checkprime()
{
    temp = head;
    int flag = 0, notprime = 0;
    while (temp != 0)
    {
        if (temp->data == 1 || (temp->data) % 2 == 0 || (temp->data) % 3 == 0)
        {
            notprime++;
        }
        for (int i = 5; i * i <= (temp->data) / 2; i = i + 6)
        {
            if ((temp->data) % i == 0 || (temp->data) % (i + 2) == 0)
            {
                notprime++;
            }
        }
        temp = temp->next;
        count++;
    }
    cprime = count - notprime;
    printf("there are %d number of prime number present in link list\n", cprime);
    printf("there are %d number of non-prime number present in link list\n", notprime);
}
struct node checkpalindrome()
{
    struct node *prev, *other, *rev;
    prev = other = NULL;
    temp = head;
    while (temp != NULL)
    {
        other = temp->next;
        temp->next = prev;
        prev = temp;
        temp = other;
    }
    rev = prev;
    while (rev != NULL && head != NULL)
    {
        if (head->data == rev->data)
        {
            printf("the link list is palindrome");
        }
        else
        {
            printf("the link list is not palindrome");
        }
        head = head->next;
    }
}
int main()
{
    while (1)
    {
        printf("\nenter 1 to create the link list:\n");
        printf("enter 2 to display the link list:\n");
        printf("enter 3 to add the node at the begening of the link list:\n");
        printf("enter 4 to add the node at the end of the link list:\n");
        printf("enter 5 to count the number of element present in the link list:\n");
        printf("enter 6 to delete a node at the begening:\n");
        printf("enter 7 to delete the node at the end:\n");
        printf("enter 8 to check number ofodd or even number present in link list\n");
        printf("enter 9 to check number of prime number present in link list\n");
        printf("enter 10 to check the link list is palindrome or not:\n");
        printf("enter 11 to exit:\n");
        int num;
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
        {
            addinbegening();
            printf("\nthe list after adding the data in the begening is:\n");
            display();
            break;
        }
        case 4:
        {
            addatend();
            printf("\nthe list after adding the data in the end is:\n");
            display();
            break;
        }
        case 5:
            countnum();
        case 6:
        {
            deleteatbegening();
            printf("the linklist after deleting a node at the begening is:\n");
            display();
            break;
        }
        case 7:
        {
            deleteattheend();
            display();
        }
        break;
        case 8:
            ceheckodd_even();
            break;
        case 9:
            checkprime();
            break;
        case 10:
        {
            checkpalindrome();
            break;
        }
        case 11:
            exit(1);
            break;
        }
    }
    return 0;
}