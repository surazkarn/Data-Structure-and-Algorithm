#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int Palindrome();
struct node
{
    int data;
    struct node* next;
};
struct node* start = NULL;
int main()
{
    int n,i,a;
    printf("\n Enter Total no. of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the Linked List data %d: ",i);
        scanf("%d",&a);
        struct node *ptr;
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->next=NULL;
        new->data=a;
        if(start==NULL)
        {
            start=new;
            ptr=start;
        }
        else
        {
            ptr->next=new;
            ptr=new;
        }
    }

    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf(" Data : %d\n",temp->data);
            temp = temp->next;
        }
    }
     if (Palindrome())
        printf("The linked list is a palindrome\n");
     else
        printf("The linked list is not a palindrome\n");
        
}
int Palindrome()
{
    struct node *prev, *rev ,*next, *temp;
    prev = next = NULL;
    temp = start;
    if (temp == NULL)
        printf(" !!! Linked List is empty !!!\n");
    else
    {
        while (temp != NULL)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        rev=prev;
        while (rev != NULL && start != NULL)
        {
            if(start->data == rev->data)
            {
                rev = rev->next;
                start = start->next;
            }
            else
                return 0;       
        }return 1;
    }
}
