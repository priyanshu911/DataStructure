#include<stdio.h>
#include<conio.h>
#define MAX 15

typedef struct stack
{
        char data[MAX];
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


char pop(stack *S)
{
    char x;
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

void push(stack *S,char x)
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
           printf("%c",S->data[S->top]);
           S->top--;
     }
}
int main()
{
     stack S;
     char x;
     init(&S);
     
     printf("Enter the String : ");
     while((x=getchar()!='\n'))
          push(&S,x);
          
     printf("\nReverse of the string is : ");
     while(!empty(&S))
     {
          x=pop(&S); 
          printf("%c",x);             
     }
     getch();
     return 0;
}
