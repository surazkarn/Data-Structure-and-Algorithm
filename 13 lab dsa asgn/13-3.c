//3. To find number of nodes in the tree.

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

int a=1;
int CountNodes(struct BST* root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		a=a+1;
		a=CountNodes(root->left);
	}
	if(root->right!=NULL)
	{
		a=a+1;
		a=CountNodes(root->right);
	}
	return a;
}

int main()
{
	int n,i,data;
	NODE *root=NULL;
	printf("\nEnter the values to create BST.\n");
		scanf("%d", &data);
	while(data!=-1)
	
	{
		root=createtree(root, data);
		printf("\nEnter the values to create BST.\n");
		scanf("%d", &data);
	} 
	printf("Total node count of the tree is %d", CountNodes(root));
			
	return 0;	
}