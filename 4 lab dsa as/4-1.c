//1.WAP to store n employee’s data such as employee name, gender, designation, department, basic pay. Calculate the gross pay of each
//employees as follows:
//Gross pay = basic pay + HR + DA
//HR=25% of basic and DA=75% of basic.

#include <stdio.h>
#include <string.h>

struct employee
{
    int id;
    char t[5];
    char n[100];
    int a;
    float bp;
} k[100], *p;
int n;

void accept()
{
    printf("Enter the Number of Employees :\n");
    scanf("%d", &n);
    p = &k[100];
    for (int i = 0; i < n; i++)
    {

        printf("\nENTER Employee %d detail\n", (i + 1));
        gets((p + i)->t);
        printf("Enter the Employee name: ");
        gets((p + i)->n);
        printf("Enter the Employee gender: ");
        gets((p + i)->n);
        printf("Enter the Employee designation: ");
        gets((p + i)->n);
        printf("Enter the Employee department: ");
        gets((p + i)->n);
        printf("BASIC PAY: ");
        scanf("%f", &(p + i)->bp);
    }
}

void display()
{
    float gp, da, hr;
    for (int i = 0; i < n; i++)
    {
        printf("\nDetail of person no %d\n", (i + 1));
        printf("\nEMPLOYEE n     : %s\n", (p + i)->n);
        printf("BASIC PAY        : %.2f\n", (p + i)->bp);
        da = 0.75 * ((p + i)->bp);
        hr = 0.25 * ((p + i)->bp);
        gp = ((p + i)->bp) + da + hr;
        printf("DA        =%.2f\n", da);
        printf("HR        =%.2f\n", hr);
        printf("GROSS PAY =%.2f\n", gp);
    }
}

void main()
{
    accept();
    display();
}