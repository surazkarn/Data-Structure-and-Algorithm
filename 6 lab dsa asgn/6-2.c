//2.WAP TO READ 3 SPARSE MATRIX AND PERFORM THEIR ADDITION USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};
void display(struct node *);
void create(struct node *ptr)
{
    int i;
    struct node *new_node, *temp;
    printf("Enter Row , Column, Value for :\n");
    for (i = 0; i < ptr->val; i++)
    {
        new_node = malloc(sizeof(struct node));
        printf("Value %d : ", i + 1);
        scanf("%d%d%d", &new_node->row, &new_node->col, &new_node->val);
        new_node->next = NULL;
        if (ptr->next == NULL)
        {
            ptr->next = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    printf("\nMATRIX :\n");
    display(ptr);
}
void display(struct node *ptr)
{
    struct node *temp = ptr;
    while (temp)
    {
        printf("%d %d %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
}
struct node *add(struct node *ptr1, struct node *ptr2)
{
    struct node *sum = malloc(sizeof(struct node));
    sum->row = ptr1->row;
    sum->col = ptr1->col;
    sum->val = 0;
    sum->next = NULL;
    struct node *t1, *t2, *temp, *new_node;
    t1 = ptr1->next;
    t2 = ptr2->next;
    temp = sum;
    while (t1 != NULL && t2 != NULL)
    {
        new_node = malloc(sizeof(struct node));
        if (t1->row == t2->row)
        {
            if (t1->col == t2->col)
            {
                new_node->row = t1->row;
                new_node->col = t1->col;
                new_node->val = t1->val + t2->val;
                t1 = t1->next;
                t2 = t2->next;
            }
            else if (t1->col < t2->col)
            {
                new_node->row = t1->row;
                new_node->col = t1->col;
                new_node->val = t1->val;
                t1 = t1->next;
            }
            else
            {
                new_node->row = t2->row;
                new_node->col = t2->col;
                new_node->val = t2->val;
                t2 = t2->next;
            }
        }
        else
        {
            if (t1->row < t2->row)
            {
                new_node->row = t1->row;
                new_node->col = t1->col;
                new_node->val = t1->val;
                t1 = t1->next;
            }
            else
            {
                new_node->row = t2->row;
                new_node->col = t2->col;
                new_node->val = t2->val;
                t2 = t2->next;
            }
        }

        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
        sum->val++;
    }

    while (t1 != NULL)
    {
        new_node = malloc(sizeof(struct node));
        new_node->row = t1->row;
        new_node->col = t1->col;
        new_node->val = t1->val;
        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
        t1 = t1->next;
        sum->val++;
    }

    while (t2 != NULL)
    {
        new_node = malloc(sizeof(struct node));
        new_node->row = t2->row;
        new_node->col = t2->col;
        new_node->val = t2->val;
        new_node->next = NULL;
        temp->next = new_node;
        temp = new_node;
        t2 = t2->next;
        sum->val++;
    }

    return sum;
}

int main()
{
    struct node *m1, *m2, *temp = NULL, *m3;
    printf("\nEnter details of 1st Matrix :\n");
    printf("Enter total no. of rows, columns & non-zero elements : ");
    m1 = malloc(sizeof(struct node));
    scanf("%d%d%d", &m1->row, &m1->col, &m1->val);
    m1->next = NULL;
    create(m1);
    printf("\nEnter details of 2nd Matrix :\n");
    printf("Enter total no. of rows, columns & non-zero elements : ");
    m2 = malloc(sizeof(struct node));
    scanf("%d%d%d", &m2->row, &m2->col, &m2->val);
    m2->next = NULL;
    create(m2);
    printf("\nEnter details of 3rd Matrix :\n");
    printf("Enter total no. of rows, columns & non-zero elements : ");
    m3 = malloc(sizeof(struct node));
    scanf("%d%d%d", &m3->row, &m3->col, &m3->val);
    m3->next = NULL;
    create(m3);
    temp = add(m1, m2);
    temp = add(temp, m3);
    printf("SUM OF 3 SPARSE MATRIX:\n");
    display(temp);
    return 0;
}
