//2. WAP to create a binary search tree and display it in preorder and postorder traversal

#include <stdio.h>
#include <stdlib.h>

struct BST
{
int data;
struct BST *left;
struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE* createtree(NODE *node, int data)
{
if (node == NULL)
{
NODE *temp;
temp= (NODE*)malloc(sizeof(NODE));
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
if (data < (node->data))
{
node->left = createtree(node->left, data);
}
else if (data > node->data)
{
node -> right = createtree(node->right, data);
}
return node;
}

void preorder(NODE *node)
{
if(node != NULL)
{
printf("%d\t", node->data);
preorder(node->left);
preorder(node->right);
}
}

void postorder(NODE *node)
{
if(node != NULL)
{
postorder(node->left);
postorder(node->right);
printf("%d\t", node->data);
}
}

int main()
{
	NODE *root=NULL;
	int i,n,data;
	printf("\nEnter N0. of value: " );
	scanf("%d", &n);
	printf("\nEnter the values to create BST.\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &data);
		root=createtree(root, data);
	}
	printf("\nPreorder Traversal: \n");
	preorder(root);
	printf("\nPostorder Traversal: \n");
	postorder(root);
	return 0;
}