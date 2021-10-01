//1.WAP to swap kth node from beginning with kth node from end in a Linked List

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct pair
{
    struct node *head, *tail;
};

struct node *takeinput()
{
    int data;
    scanf("%d", &data);
    struct node *head = NULL;
    struct node *tail = NULL;
    while (data != -1)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        scanf("%d", &data);
    }
    return head;
}
int count(struct node *head)
{
    struct node *temp = head;
    int c = 0;
    while (temp->next != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
void swap(struct node *head, int s_p, int e_p)
{
    struct node *temp = head;
    //int k=count(head);
    //int i=0;
    printf("h");
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\nd");
    printf("%d", c);
    printf("%d", head->data);
    struct node *t = head;
    for (int i = 0; i < c; i++)
    {
        if (i == s_p)
        {
            printf("%d", t->data);
        }
        temp = temp->next;
    }
    int l = c - e_p, j = 0;
    for (; j < c; j++)
    {
        if (j == l)
        {
            printf("\n%d", t->data);
        }
        temp = temp->next;
    }
}
void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head = takeinput();
    print(head);
    int s_po, e_po;
    scanf("%d%d", &s_po, &e_po);
    swap(head, s_po, e_po);
}