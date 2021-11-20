//3. WAP to create a binary search tree and find the smallest element.

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

int smallestElement(NODE *temp){  
    if(temp == NULL) {  
    return 0;
    }  
    else{  
        int leftMin, rightMin;  
        int min = temp->data;  
        if(temp->left != NULL){  
            leftMin = smallestElement(temp->left);  
            min = (min > leftMin) ? leftMin : min;  
        }  
        if(temp->right != NULL){  
            rightMin = smallestElement(temp->right);  
            min = (min > rightMin) ? rightMin : min;  
        }  
    return min; 
    }  
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
	
	if(smallestElement(root)==0)
		printf("Tree is empty\n");
	else
		printf("%d is smallest Element",smallestElement(root));
	return 0;
}