#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct stack
{
        int data;
        struct stack *next;       
}stack;

stack * init()
{
     stack *top;
     top=NULL;      //make the stack empty
     return top;
}

int empty(stack *top)
{
    if(top==NULL)
         return (1);
    return (0);
}



int pop(stack *top)
{
    stack *P;
    int x;
    if(!empty(top))
    {      
          P=top;
          top=top->next;
          x=P->data;
          free(P);
          return x;
    }   
    else
    {
        printf("\nStack is empty\n");
        return ('\0');
    }
}

stack * push(stack *top,int x)
{
     stack *P;
     P=(stack*)malloc(sizeof(stack));
     P->data = x;
     P->next=top;
     top=P;
     return top;
}

void display(stack *top)
{
     int x;
     while(!empty(top))
     {
           x=pop(top);
           printf("\t%d",x);                // printf("\t%d",top->data); top=top->next;
     }
}
int main()
{
     stack *Top;
     int i,j,x,choice;
     Top=init();
     //init(&Top);
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
                  Top=push(Top,x);
                  break;
             }
             
             case 2:
             {
                  pop(Top);
                  break;
             }
             
             case 3:
             {
                  printf("\nThe Stack is \n\n");
                  display(Top);
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
