//2.WAP to sort the elements inside a stack using only push and pop operation. 
//Any number of additional stacks may be used.

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *ptr;
};

void create(struct stack **s)
{
     *s = NULL;
}

int isEmpty(struct stack *s)
{
     if (s == NULL)
            return 1;
     return 0;
}

void push(struct stack **s, int data)
{
  struct stack *temp = (struct stack *)malloc(sizeof(*temp));
  if (temp == NULL)
  {
      return;
  }
  temp->data = data;
  temp->ptr = *s;
  *s = temp;
}

int pop(struct stack **s)
{
   int data;
   struct stack *temp;
   data = (*s)->data;
   temp = *s;
   (*s) = (*s)->ptr;
   free(temp);
   return data;
}

int top(struct stack *s)
{
  return (s->data);
}

void sort_stack_and_insert(struct stack **s, int data)
{
  if (isEmpty(*s) || data > top(*s))
  {
     push(s, data);
     return;
  }
  int temp = pop(s);
  sort_stack_and_insert(s, data);
  push(s, temp);
}

void sort_stack(struct stack **s)
{
   if (!isEmpty(*s))
   {
    int data = pop(s);
    sort_stack(s);
    sort_stack_and_insert(s, data);
   }
}

void display(struct stack *s)
{
 while (s)
  {
      printf("%d ", s->data);
      s = s->ptr;
 }
 printf("\n");
}

int main(void)
{
struct stack *top;
 create(&top);
 int n;
 printf("\nEnter the number of elements to be pushed to the stack : ");
 scanf("%d",&n);
  int i,data;
  printf("\nInput the stack elements : ");
  for(i = 0; i < n; i++)
    {
        scanf("%d",&data);
        push(&top, data);
    }
printf("\n");
sort_stack(&top);
printf("Sorted Stack : ");
display(top);
return 0;
}