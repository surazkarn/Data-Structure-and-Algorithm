//4. WAP to insert a new node at the beginning of a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;

struct node
{
	int data;
	struct node *next, *prev;
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
		new_node->next=NULL;
		new_node->prev=NULL;
		new_node->data=num;
 
		if(head==NULL)
		{
			head=new_node;
			ptr=head;
		}
		else
		{
			ptr->next=new_node;
			new_node->prev=ptr;
			ptr=new_node;
		}
		printf("Enter Data: ");
		scanf("%d",&num);
	}
	return head;
}

struct node *display(struct node *head)
{
	if(head==NULL)
		printf("\nThe Linked List is Empty\n");
	else
	{
		struct node *ptr=head;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	return head;
}

struct node *insert(struct node *head)
{
	struct node *new_node;
	int num;
	printf("Enter Data to be Inserted: ");
	scanf("%d", &num);

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->prev=NULL;
	new_node->data=num;
	new_node->next=head;
	head->prev=new_node;
	
	head=new_node;
	
	return head;
}

int main()
{
	int ch;
	printf("****DOUBLY LINKED LIST MAIN MENU****\n");
	do
	{
		printf("1. Create a Doubly Linked List\n");
		printf("2. Traverse the Linked List\n");
		printf("3. Insert a Node at the Beginning\n");
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
			head=insert(head);
			printf("\n****LINKED LIST MODIFIED****\n\n");
		}
	}while(ch!=4);
}
