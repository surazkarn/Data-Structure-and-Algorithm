//2.WAP to reverse the sequence elements in a double linked list.


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

struct node* create( struct node *head)
{
  struct node *newnode,*ptr;
  int num;
  printf("\npress -1 to stop : \n" );
  printf("Enter the number : " );
  scanf("%d",&num);
  while (num!=-1)
   {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;
     newnode->data=num;

    if(head==NULL)
    {
      head=newnode;
      ptr=head;
    }
    else
    {
      ptr->next=newnode;
      newnode->prev=ptr;
      ptr=newnode;
    }
    printf("Enter the number : " );
    scanf("%d",&num );
   }
  return head;
  }

 struct node display(struct node *head)
  {
    struct node *ptr;
    ptr =head;
    while (ptr!=NULL)
     {
      printf("%d\t",ptr->data );
      ptr=ptr->next;
    }
    return *head;
  }

struct node *reverse(struct node *head)
{
    struct node *temp=head;
    struct node *temp2=temp->next;

    temp->next=NULL;
    temp->prev=temp2;

    while(temp2!=NULL)
    {
        temp2->prev=temp2->next;
        temp2->next=temp;
        temp=temp2;
        temp2=temp2->prev;
    }
    head=temp;
    return head;
}
int main()
{
    int ch;

    do{
        printf("\npress 1 to create link list.\n");
        printf("press 2 to display link list.\n");
        printf("press 3 to reverse link list.\n");
        printf("press 4 to exit.");
        printf("\nPlease enter your choice : ");
        scanf("%d",&ch);

        if(ch==1)
        {
            head=create(head);
        }
        if (ch==2)
        {
             printf("displaing link list\n");
              *head=display(head);
        }
        if(ch==3)
        {
            head=reverse(head);
            printf("Reversed link list is :");
            *head=display(head);
        }

    }while(ch!=4);
}