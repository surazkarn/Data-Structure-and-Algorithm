//6. To find nodes which are at maximum depth in the tree?

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

int Depth(struct BST * root)
{
	if (root == NULL)
		return 0;
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	if (leftDepth > rightDepth)
		return leftDepth + 1;
	else
		return rightDepth + 1;
}

int printcurrentlevel(struct BST *root,int level)
{
	if(root == NULL)
		return 0;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
	{
		printcurrentlevel(root->left,level-1);
		printcurrentlevel(root->right,level-1);
	}
}

int main()
{
	int n,i,data;
	NODE *root=NULL;
	printf("\nEnter N value: " );
	scanf("%d", &n);
	printf("\nEnter the values to create BST.\n");
	for(i=0; i<n; i++)
		{
			scanf("%d", &data);
			root=createtree(root, data);
		}
	printf("\nNodes at maximum depth : ");
	printcurrentlevel(root,Depth(root));
	printf("\n");
			
	return 0;	
}