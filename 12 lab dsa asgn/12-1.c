//1. WAP to create a binary search tree and display it(inorder traversal)

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;
void insert(node *, node *);
void inorder(node *);
void main() {
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *tmp, *parent;
   node *get_node();
   root = NULL;
   printf("\nProgram For Binary Search Tree ");
        do{
            new_node = get_node();
            printf("\nEnter The Element ");
            scanf("%d", &new_node->data);

            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);

            printf("\nWant To enter More Elements?(y/n)");
            ans = getch();
         } while (ans == 'y');
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nThe Inorder display : ");
            inorder(root);
         }
}
/*
 Get new Node
 */
node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
/*
 This function is for creating a binary search tree
 */
void insert(node *root, node *new_node) {
   if (new_node->data < root->data) {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }

   if (new_node->data > root->data) {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}
/*
 This function displays the tree in inorder fashion
 */
void inorder(node *temp) {
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d", temp->data);
      inorder(temp->rchild);
   }
}