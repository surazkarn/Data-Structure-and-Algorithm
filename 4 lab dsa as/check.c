#include <stdio.h>
#include <string.h>
struct employee
{
    float basic_pay;
    char name[20];
    char gender[10];
    char designation[20];
    char department[20];
};

int main()
{
    int n, i;
    float gross,HR,DA;
    printf("Enter the number of the employee : ");
    scanf("%d", &n);
    struct employee b[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the details of the employee no. : %d\n",i+1);
        printf("Name : ");
        scanf("%s",b[i].name);
        printf("Gender : ");
        scanf("%s",b[i].gender);
        printf("Designation : ");
        scanf("%s",&b[i].designation);
        printf("Department : ");
        scanf("%d",&b[i].department);
        getchar;
        printf("Basic Pay  : ");
        scanf("%f",&b[i].basic_pay);
    }
    // printf("S.N | NAME | GENDER | DESIGNATION | DEPARTMENT | BASIC PAY | GROSS PAY |\n");
    for(i=0;i<n;i++)
    {
        // printf("%2d%s%s%s%s%f%f"i,b[i].name);
        printf("The details of the employee no. %d\n",i+1);
        printf("Name : %s\n",b[i].name);
        printf("Gender : %s\n",b[i].gender);
        printf("Designation : %s",b[i].designation);
        printf("Department : %s\n",b[i].department);
        printf("Basic pay : %d",b[i].basic_pay);
        HR= b[i].basic_pay*0.25;
        DA=b[i].basic_pay*0.75;
        gross=b[i].basic_pay+HR+DA;
        printf("Gross Pay : %f\n",gross);
    }

    return 0;
}