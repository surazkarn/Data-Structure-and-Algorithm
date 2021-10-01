//8.WAP to print the middle of a double linked list.

#include <stdio.h>  
#include <stdlib.h>
struct node
{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      

struct node *head, *tail = NULL;  

void addNode(int data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
    }  
}  

void middle()

    {
        struct node* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }

        temp=head;
        int p=1;
        if(c%2==0)
        {
            int mid=c/2;
            while(temp!=NULL)
            {
                if(p==mid)
                    break;
                p++;
                temp=temp->next;
            }
            printf("%d%d",temp->data , temp->next->data);
        }
        else
        {
            int mid=(c+1)/2;
            while(temp!=NULL)
            {
                if(p==mid)
                    break;
                p++;
                temp=temp->next;
            }
            printf("%d",temp->data);
        }
    }

/*
 void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer.  
        printf("%d ", current->data);  
        current = current->next;  
    }  
}
*/
int main()  
{  
    addNode(9);  
    addNode(7);  
    addNode(6);  
    addNode(56);  
    addNode(89);  
    //display();  
    middle();

    return 0;  
    }