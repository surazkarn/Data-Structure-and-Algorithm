//1. WAP TO ADD TWO POLYNOMIAL OF 2 VARIABLE (EX. 2X^2Y^3+XY+1, 5X^5Y+7XY+5) USING LINKED LIST

#include <stdio.h>
#include <malloc.h>
struct node
{
    int coeff,powX,powY;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;

struct node *create_poly(struct node *start)
{
    struct node *new_node, *ptr;
    int c, px,py;
    printf("\n Enter the coefficient:");
    scanf("%d", &c);
    printf("\n Enter the power of X and Y :");
    scanf("%d%d", &px,&py);
    while (px != -1||py!=-1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->coeff = c;
        new_node->powX = px;
        new_node->powY=py;
        new_node->next = NULL;
        if (start == NULL)
        {

            start = new_node;
            ptr = start;
        }
        else
        {

            ptr->next = new_node;
            ptr = new_node;
        }
        printf("\n Enter the coefficient:");
        scanf("%d", &c);
        printf("\n Enter the power of X and Y:");
        scanf("%d%d", &px,&py);
    }
    return start;
}
struct node *display_poly(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {  
        printf(" %dX^%dY^%d ", ptr->coeff, ptr->powX,ptr->powY);
        if(ptr->next!=NULL)
        {
            printf(" + ");
        }
        ptr = ptr->next;
    }
    return start;
}
struct node *add_node(struct node *start, int c, int px,int py)
{
    struct node *ptr, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->coeff = c;
    new_node->powX = px;
    new_node->powY=py;
    new_node->next = NULL;
    if (start == NULL)
    {
        start = new_node;
        ptr = new_node;
    }
    else
    {
        ptr->next = new_node;
        ptr = new_node;
    }
    return start;
}
struct node *add_poly(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1, *ptr2;
    int sum;
    ptr1 = start1;
    ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->powX == ptr2->powX && ptr1->powY==ptr2->powY)
        {
            sum = ptr1->coeff + ptr2->coeff;
            start3 = add_node(start3, sum, ptr1->powX,ptr1->powY);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->powX > ptr2->powX||ptr1->powY>ptr2->powY)
        {
            start3 = add_node(start3, ptr1->coeff, ptr1->powX,ptr1->powY);
            ptr1 = ptr1->next;
        }
        else if (ptr1->powX < ptr2->powX||ptr1->powY<ptr2->powY)
        {
            start3 = add_node(start3, ptr2->coeff, ptr2->powX,ptr2->powY);
            ptr2 = ptr2->next;
        }
        // else if(ptr1->powX<)
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            start3 = add_node(start3, ptr2->coeff, ptr2->powX,ptr2->powY);
            ptr2 = ptr2->next;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            start3 = add_node(start3, ptr1->coeff, ptr1->powX,ptr2->powY);
            ptr1 = ptr1->next;
        }
    }
    return start3;
}
int main()
{
    printf("\n Enter the first polynomial");
    start1 = create_poly(start1);
    printf("\n Display the first polynomial");
    start1 = display_poly(start1);
    printf("\n Enter the second polynomial");
    start2 = create_poly(start2);
    printf("\n Display the second polynomial");
    start2 = display_poly(start2);
    printf("\n Add the two polynomials");
    start3 = add_poly(start1, start2, start3);
    printf("\n Display the result");
    start3 = display_poly(start3);
    return 0;
}