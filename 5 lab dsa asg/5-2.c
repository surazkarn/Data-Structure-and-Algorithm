#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;
static int n;

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
		n++;
		
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
	return head;
}

struct node *display(struct node *head)
{
	if(head==NULL)
		printf("\nThe Linked List is Empty\n");
	else
	{
		n=0;
		struct node *ptr=head;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
	return head;
}

struct node *reverse (struct node *head, int k)
{
    if (!head)
        return NULL;
   
    struct node *ptr = head, *next = NULL, *prev = NULL;
    int c=0;

    while (ptr!=NULL && c<k)
    {
        next  = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
        c++;
    }

    if (next!=NULL)
		head->link=reverse(next, k);
    return prev;
}

int main()
{
	int ch;
	printf("****LINKED LIST MAIN MENU****\n");
	do
	{
		printf("1. Create a Linked List\n");
		printf("2. Traverse the Linked List\n");
		printf("3. Reverse Every K Node\n");
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
			int k;
			printf("Enter K (<%d): ", n);
			scanf("%d", &k);
			head=reverse(head, k);
		}
	}while(ch!=4);
}
