#include<stdio.h>
#include <stdlib.h> //for malloc function

//create structure
struct Node{
  int data;
  struct Node*next;
};
//function prototype
void insert(struct Node**,int);
void display(struct Node*);
//insert Node element
void insert(struct Node**head,int value){
  //Create dynamic node
  struct Node*node=(struct Node*)malloc(sizeof(struct Node));
  if(node==NULL){
    printf("Memory overflow\n");
  }else{
    node->data=value;
    node->next=NULL;
    if(*head==NULL){
      *head=node;
    }else{
      struct Node*temp=*head;
      //find last node
      while(temp->next!=NULL){
        temp=temp->next;
      }
      //add node at last possition
      temp->next=node;
    }
  }
}
//find second smallest element in linked list node
void second_smallest(struct Node*temp){

  if(temp!=NULL){

      if(temp->next==NULL){
        printf("Only one node of linked list\n");
      }else{

       struct Node*first=NULL,*second=NULL;
        if(temp->data > temp->next->data){
            first=temp->next;
            second=temp;
        }else{
          first=temp;
          second=temp->next;
        }
        while(temp!=NULL){
          if(temp->data<first->data){
            //Get smallest node

            if(second->data>first->data){
              //find new smallest node
              second=first;
            }
            first=temp; 
          }else if(temp->data<second->data && temp->data>first->data){
            //when node value greater than smallest value but less than second node value
            second=temp;
          }else if(first->data==second->data && temp->data > first->data){
            //When first and second are same value nodes
            //and next upcomming are our second node
            second=temp;
          }
          temp=temp->next;
        }
        printf("\nSecond smallest : %d\n",second->data);
      }

  }else{
    printf("Empty Linked List\n");
  }

}
//Display element of Node
void display(struct Node*temp){
  
  if(temp==NULL){
    printf("Empty linked list");
  }
  while(temp!=NULL){
    printf("%d  ",temp->data);
    temp=temp->next;
  }
}
int main(){
  //create node pointer
  struct Node*head=NULL;
  //insert element of linked list


  insert(&head,7);
  insert(&head,1);
  insert(&head,4);
  insert(&head,2);
  insert(&head,5);
  insert(&head,3);
  insert(&head,1);
  //display all node
  display(head);
  second_smallest(head);
  return 0;
}