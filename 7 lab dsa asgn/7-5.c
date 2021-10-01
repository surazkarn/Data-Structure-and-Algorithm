//5.WAP to remove the duplicates in a sorted double linked list.

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
  struct node *next,*prev;
};

struct node *start=NULL;


struct node * create_ll(struct node *start)
{

  struct node *new_node,*ptr;
  int num;
  printf("\n Enter -1 to end");
  printf("\n Enter the data :");
  scanf("%d",&num);

  while(num != -1)
  {

   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=num;

   new_node->next=NULL;
new_node->prev=NULL;



   if(start==NULL)
   {
   
     start=new_node;
     ptr=start;
   }
   else
   {

     ptr->next=new_node;
     new_node->prev=ptr;
     ptr=new_node;

    
    }
    printf("\n Enter the data :");
    scanf("%d",&num);
   }
 return start;
}

struct node * display(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr != NULL)
  {

    printf("\t %d",ptr->data);
    ptr=ptr->next;
  }
  return start;
}

void removeduplicate()
{
	struct node *ptr, *index, *temp;
	if (start==NULL)
		return;
	else
	{
		for (ptr=start;ptr!=NULL;ptr=ptr->next)
		{
			for (index=ptr->next;index!=NULL;index=index->next)
			{
				if (ptr->data==index->data)
				{
					
					index->prev->next=index->next;
					if (index->next=NULL)
					{
						index->next->prev=index->prev;
					}
				}
			}
		}
	}
}

int main()
{
	printf("Creating a Doubly Linked List:\n");
	start=create_ll(start);
	printf("\nDisplaying the list: ");
	start=display(start);
	printf("\n After Deleting Duplicate Nodes:\nList: ");
	removeduplicate();
	start=display(start);
	return 0;
}
