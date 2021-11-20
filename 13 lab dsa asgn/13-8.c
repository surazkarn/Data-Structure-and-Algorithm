//8. To find the common ancestor and print the paths.

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



struct BST* findLCA(struct BST* root, int n1, int n2)
{
	if (root == NULL)
	return NULL;

	if (root->data == n1 || root->data == n2)
	return root;

	struct BST* left_lca = findLCA(root->left, n1, n2);
	struct BST* right_lca = findLCA(root->right, n1, n2);

	if (left_lca && right_lca)
	return root;
	return (left_lca != NULL) ? left_lca : right_lca;
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
	
	printf("Enter two node values to find common ancestor: ");
	scanf("%d %d",&a,&b);
	struct  BST *temp= findLCA(root,a,b);
	temp==NULL? printf("Atleast one node doesn't exist.\n ") : printf("\nThe common ancestor is %d.\n",temp->data);
			
	return 0;	
}