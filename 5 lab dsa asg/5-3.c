#include<stdio.h>
#include<stdlib.h>

struct node *head = NULL;
static int n=0;

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

struct node *rotate(struct node *head, int k)
{
    if (k==0)
        return head;
 
    struct node* ptr=head;

    int c=1;
    while (c<k)
    {
        ptr = ptr->link;
        c++;
    }

    if (ptr==NULL)
        return 0;
 
    struct node* temp= ptr;
    while (ptr->link!=NULL)
        ptr = ptr->link;
        
    ptr->link = head;
    head = temp->link;
    temp->link = NULL;
    
    return head;
}

int main()
{
	int ch;
	printf("****LINKED LIST MAIN MENU****\n");
	do
	{
		printf("1. Create a Linked List\n");
		printf("2. Traverse the Linked List\n");
		printf("3. Rotate LL Clockwise after K Nodes\n");
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
			head=rotate(head, k);
		}
	}while(ch!=4);
}
