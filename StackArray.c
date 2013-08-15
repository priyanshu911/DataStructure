#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct stack
{
        int data[MAX];
        int top;        
}stack;

void init(stack *S)
{
     S->top=-1;     
}

int empty(stack *S)
{
    if(S->top==-1)
         return (1);
    return (0);
}

int full(stack *S)
{
    if(S->top==(MAX-1))
         return (1);
    return (0);
}


int pop(stack *S)
{
    int x;
    if(!empty(S))
    {      
          x =  S->data[S->top];
          S->top--;
          return x;
    }   
    else
    {
        printf("\nStack is empty\n");
        return ('\0');
    }
}

void push(stack *S,int x)
{
     if(!full(S))
     {
         S->top++;
         S->data[S->top]=x;    
     }
     else
     {
         printf("\nStack is full\n");
     }
}

void display(stack *S)
{
     while(S->top!=-1)
     {
           printf("\t%d",S->data[S->top]);
           S->top--;
     }
}

int main()
{
     stack S;
     int i,j,x,choice;
     init(&S);
     do{
         printf("\n\nEnter 1 to push \n");
         printf("Enter 2 to pop \n");
         printf("Enter 3 to display \n");
         printf("Enter 4 to exit \n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             {
                  printf("Enter the data to be pushed : ");
                  scanf("%d",&x);
                  push(&S,x);
                  break;
             }
             
             case 2:
             {
                  pop(&S);
                  if(x!=0)
                       printf("\nElement deleted is :  %d ",x);
                  break;
             }
             
             case 3:
             {
                  printf("\nThe Stack is \n\n");
                  display(&S);
                  break;
             }
             
             case 4:
             {
                  exit(0);
             }
             
             default:
             {
                  printf("\nInvalid Choice");
             }
         }
     }while(choice!=4);
     
     getch();
     return 0;
}
