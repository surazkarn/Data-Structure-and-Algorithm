//1.To count number of leaf nodes in the tree.

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* getNewNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
   
  return newNode;
}

struct node* generateBTree(){
    struct node* root =  getNewNode(1);
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);
    root->left->left->left = getNewNode(8);
    return root;
 
}
int countLeafNode(struct node *root){
  
    if(root == NULL)
        return 0;
      if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNode(root->left) + countLeafNode(root->right);
}
 
int main() {
    struct node *root = generateBTree();  
    printf("Number of leaf Node : %d", countLeafNode(root));
    return 0; 
}



/*
            1
           / \
         2    3
        / \  / \
       4  5 6  7
      /
     8
*/