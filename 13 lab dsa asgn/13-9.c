//9.To check whether a tree is a binary search tree or not.

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

int isBSTUtil(struct BST* BST, int min, int max)
{
	if (BST==NULL)
	return 1;
	if (BST->data < min || BST->data > max)
	return 0;
	return
	isBSTUtil(BST->left, min, BST->data-1) && isBSTUtil(BST->right, BST->data+1, max);
}

int isBST(struct BST* BST)
{
  return(isBSTUtil(BST, INT_MIN, INT_MAX));
}


int main()
{
	int n,i,data,a,b;
	NODE *root=NULL;
	printf("\nEnter N value: " );
	scanf("%d", &n);
	printf("\nEnter the values to create BST.\n");
	for(i=0; i<n; i++)
		{
			scanf("%d", &data);
			root=createtree(root, data);
		}
	
	if(isBST(root))
		printf("The tree is a Binary Search Tree.\n");
	else
		printf("The tree is not a Binary Search Tree.");
			
	return 0;	
}