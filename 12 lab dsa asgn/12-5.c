//5. WAP to create a binary search tree and find the total number of nodes.

#include <stdio.h>
#include <stdlib.h>

struct BST
{
   int data;
   struct BST *left;
   struct BST *right;
};
int count=0;
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
void inorder(NODE *node)
{
    // int count=0;
   if(node != NULL)
   {
     inorder(node->left);
     printf("%d\t", node->data);
     inorder(node->right);
     count++;
   }
//    printf("\n total number of traversal is: %d\n",count);
}

void main()
{
   int data, ch, i, n;
   NODE *root=NULL;
     root=createtree(root, 90);
   root=createtree(root, 3);
   root=createtree(root, 12);
   root=createtree(root, 97);
   root=createtree(root, 15);
   printf("\nInorder Traversal: \n");
   inorder(root);
   printf("\n total number of traversal is: %d\n",count);
}