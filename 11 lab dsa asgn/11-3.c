//3. Design a stack that supports getMin() in O(1) time and O(1) extra space

#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1,min;
int st[MAX];
int isEmpty();
void push(int);
void pop();
void display();
void getMin();
int main()
{
 int val,option,size;
 do
 {
        printf("\n**MAIN MENU**");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. GET MINIMUM");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d",&option);

        switch(option)
        {

           case 1:
               printf("\n Enter the number to be pushed in stack :");
               scanf("%d",&val);
               push(val);
               break;
           case 2:
               pop();
               break;
           case 3:
               display();
               break;
           case 4:
           	   getMin();
           	   break;
        }
    
}while(option !=5);

}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
    void getMin(){ 
        if(isEmpty()){ 
            printf("Stack is empty\n"); 
        }
        else{
            printf("Minimum element : %d",min); 
        }    
    } 
  
    void pop(){ 
        if(isEmpty()){ 
            printf("Stack is empty\n"); 
            return; 
        } 
  
       printf("Popped element : "); 
        int t = st[top--]; 
        if(t<min){ 
            printf("%d \n",min); 
            min = 2*min - t; 
        } 
  
        else{
            printf("%d\n",t);
        }    
    } 
  
    void push(int x){ 
        if(isEmpty()){ 
            min = x;
			st[top++]=x; 
            return; 
        } 
  
        if(x < min){ 
        st[top++]=2*x-min;
            
            min = x; 
        } 
  
        else{
           st[top++]=x;
        }   
    } 
 
 
void display()
{
    int i;
    if(isEmpty())
    {
     printf("\nStack is empty");
    }  
  else
  {
  	printf("Stack elements are:\n");
    for(i=top;i>=0;i--)
      printf("\n%d",st[i]);
  }
}