//7.WAP to remove the duplicates in a sorted double linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node *next;
  struct Node *prev;
};

//insert Node element end of linked list
void insert(struct Node **head, int value) 
{

  //Create a dynamic node
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  if (node == NULL) 
  {
    printf("Memory overflow\n");
  } 
  else 
  {
    //set data value
    node -> data = value;
    node -> next = NULL;
    node -> prev = NULL;
    if ( *head == NULL) 
    {
      *head = node;
    } 
    else 
    {
      struct Node *temp = *head;
      //find last node
      while (temp != NULL && temp -> next != NULL) 
      {
        temp = temp -> next;
      }
      //add new node to last positions
      temp -> next = node;
      node -> prev = temp;

    }
  }
}
//display element of Node
void display(struct Node *temp) 
{

  if (temp == NULL) 
  {
    printf("Empty linked list");
  } 
  else 
  {
    //Traverse doubly linked list from front to rear
    while (temp != NULL) 
    {
      //print node value
      printf("%d  ", temp -> data);
      temp = temp -> next;
    }
  }
}
//delete duplicates from doubly linked list 
void remove_node(struct Node *head) 
{

  if (head != NULL) 
  {

    struct Node *temp = head -> next, *find = NULL;

    while (temp != NULL) 
    {
      //duplicate nodes
      if (temp -> prev -> data == temp -> data) 
      {
        find = temp;

      }
      temp = temp -> next;

      if (find != NULL) 
      {
        //When find deleted node
        if (find -> prev != NULL) 
        {
          find -> prev -> next = temp;
        }
        if (temp != NULL) 
        {
          temp -> prev = find -> prev;
        }
        find -> prev = NULL;
        find -> next = NULL;
        //Free node element
        free(find);
        find = NULL;
      }
    }
  }
}
int main() 
{
  //set node pointer value
  struct Node *head = NULL;
  //Insert element of linked list
  insert( & head, 3);
  insert( & head, 3);
  insert( & head, 7);
  insert( & head, 9);
  insert( & head, 9);
  insert( & head, 9);
  insert( & head, 11);
  insert( & head, 12);
  insert( & head, 12);


  printf("Before Delete duplicate nodes : \n");
  //display all node
  display(head);
  printf("\nAfter Delete duplicate nodes : \n");
  remove_node(head);
  display(head);
}