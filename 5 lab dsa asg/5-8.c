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

int palin(struct node *head)
{
	struct node *ptr=head, *p;
	int c=1;
	while(ptr->next!=NULL)
		ptr=ptr->next;

	p=ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==p->data)
		{
			ptr=ptr->next;
			p=p->prev;
		}
		else
		{
			c--;
			break;
		}
	}
	return c;
}

int main()
{
	int ch;
	printf("****DOUBLY LINKED LIST MAIN MENU****\n");
	do
	{
		printf("1. Create a Doubly Linked List\n");
		printf("2. Traverse the Linked List\n");
		printf("3. Check if the LL is Palindrome or Not\n");
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
			int c=palin(head);
			if(c==1)
				printf("\n****Given Linked List is Palindrome****\n\n");
			else
				printf("\n****Given Linked List is not Palindrome****\n\n");
		}
	}while(ch!=4);
}
