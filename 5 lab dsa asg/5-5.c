#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;

struct node
{
	int data;
	struct node *link;
};

struct node *create(struct node *head)
{
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to Stop.\n");
	printf("Enter Data: ");
	scanf("%d", &num);
	while(num!=-1)
	{
		new_node = (struct node *) malloc(sizeof(struct node));
		new_node->link=NULL;
		new_node->data=num;
 
		if(head==NULL)
		{
			head=new_node;
			ptr=head;
		}
		else
		{
			ptr->link=new_node;
			ptr=new_node;
		}
		printf("Enter Data: ");
		scanf("%d",&num);
	}
	ptr->link=head;
	return head;
}

struct node *display(struct node *head)
{
	if(head==NULL)
		printf("\nThe Linked List is Empty\n");
	else
	{
		struct node *ptr=head;
		do
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
			
		}while(ptr!=head);
	}
	return head;
}

struct node *delete(struct node *head)
{
	struct node *ptr=head, *ptrnxt=head->link;
	int num;
	printf("Enter the Data after which the Node is to be Deleted: ");
	scanf("%d", &num);
	
	while(ptr->data!=num)
	{
		ptr=ptr->link;
		ptrnxt=ptrnxt->link;	
	}
	ptr->link=ptrnxt->link;
	free(ptrnxt);
	
	return head;
}

int main()
{
	int ch;
	printf("****CIRCULAR LINKED LIST MAIN MENU****\n");
	do
	{
		printf("1. Create a Linked List\n");
		printf("2. Traverse the Linked List\n");
		printf("3. Delete a Node after a Certain Node\n");
		printf("4. Exit\n");
		printf("Enter Choice: ");
		scanf("%d", &ch);
		
		if(ch==1)
		{
			head=create(head);
			printf("\n****LINKED LIST CREATED****\n\n");
		}
		else if(ch==2)
		{
			printf("\nDisplaying Linked List:\n");
			head=display(head);
			printf("\n\n");
		}
		else if(ch==3)
		{
			head=delete(head);
			printf("\n****LINKED LIST MODIFIED****\n\n");
		}
	}while(ch!=4);
}
