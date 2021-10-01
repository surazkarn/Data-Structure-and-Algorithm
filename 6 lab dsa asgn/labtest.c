#include<stdio.h>
#include <malloc.h>
struct node
{
int data;
struct node * next;
};
struct node* createlink(struct node* head)
{
int num;
struct node*ptr,*new_node;
printf("Enter -1 to terminate ");
printf("\nEnter the data ");
scanf("%d",&num);
while(num != -1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node->next = head;
new_node->data = num;
if(head == NULL)
{
head = new_node;
ptr = head;
}
else
{
ptr->next = new_node;
ptr= ptr->next;
}
printf("\nEnter the data ");
scanf("%d",&num);
}
return head;
}
void display(struct node*head)
{
struct node* ptr = head;
while(ptr->next != head)
{
printf("\n\n%d",ptr->data);
ptr = ptr->next;
}
printf("\t%d",ptr->data);
}
struct node* multiply(struct node* head1, struct node* head2)
{
// assuming length of the Circular linked lists to be same
struct node* ptr1 = head1->next;
struct node* ptr2 = head2->next;
head1->data= head1->data * head2->data;
while(ptr1 != head1)
{
ptr1->data= ptr1->data * ptr2->data;
ptr1 = ptr1->next;
ptr2 = ptr2->next;
}
return head1;
}
struct node* merge(struct node* head1, struct node* head2)
{
struct node* ptr1 = head1;
struct node* ptr2 = head2;
while(ptr1->next != head1)
{
ptr1 = ptr1->next;
ptr2 = ptr2->next;
}
ptr1-> next= head2;
ptr2->next= head1;
return head1;
}
struct node* rotate(struct node* head, int num)
{
struct node* ptr1= head;
int i=0;
while(i<num)
{
ptr1= ptr1->next;
i++;
}
return ptr1;
}
int main()
{
struct node* head = NULL;
struct node* cll1_head, *cll2_head, *cll3_head;
cll1_head= createlink(head);
cll2_head= createlink(head);
cll3_head= createlink(head);
printf("\nThe 1st list is:\n");
display(cll1_head);
printf("\n");
printf("\nThe 2nd list is:\n");
display(cll2_head);
printf("\n");
printf("\nThe 3rd list is:\n");
display(cll3_head);
printf("\n");
// Since my roll number is 20051761 which is odd
struct node *result_cll= multiply(cll1_head,cll3_head);
printf("\n The multiplied list is:\n ");
display(result_cll);
printf("\n");
struct node *merged_cll= merge(result_cll,cll2_head);
printf("\n The merged list is: \n");
display(merged_cll);
printf("\n");
int to_rotate= (20051761%10) ;
struct node *rotated_cll= rotate(merged_cll,to_rotate);
printf("\n The final list is: \n");
display(rotated_cll);
printf("\n");
return 0;
}