//5. To print depth of the tree.

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
	printf("Depth of the tree is %d", Depth(root));
			
	return 0;	
}