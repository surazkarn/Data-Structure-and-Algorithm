//4. WAP to create a binary search tree and find the largest element.

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

int largestElement(NODE* root) 
{ 
    if (root == NULL) 
    return 0;
    int res = root->data; 
    int lres = largestElement(root->left); 
    int rres = largestElement(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
}

int main()
{
	NODE *root=NULL;
	int i,n,data;
	printf("\nEnter No. of value: " );
	scanf("%d", &n);
	printf("\nEnter the values to create BST.\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &data);
		root=createtree(root, data);
	}
	
	if(largestElement(root)==0)
		printf("Tree is empty\n");
	else
		printf("%d is largest Element",largestElement(root));
	return 0;
}