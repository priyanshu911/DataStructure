#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct stack
{
        int data;
        struct stack *next;       
}stack;

void init(stack **top)
{
     *top=NULL;      //make the stack empty
}

int empty(stack *top)
{
    if(top==NULL)
         return (1);
    return (0);
}


void push(stack **top,int x)
{
     stack *P;
     P=(stack*)malloc(sizeof(stack));
     P->data = x;
     P->next=*top;
     *top=P;
}


int pop(stack **top)
{
    stack *P;
    int x;
    //if(!empty(*top))    
          P=*top;
          *top=P->next;
          x=P->data;
          free(P);
          return x;
    
}


void display(stack *top)
{
     int x=top->data;
     while (top!=NULL)
     {
	      printf("%d  ",top->data);
	      top=top->next;
     }
    
     if(x==0)
     {
           printf("Empty \n");        
     }
     
     /* while(!empty(top))
     {
           x=pop(&top);
           printf("%d  ",x);               
     }
     */
}
int main()
{
     stack *Top;
     int i,j,x,choice;
     init(&Top);
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
                  push(&Top,x);
                  break;
             }
             
             case 2:
             { 
                 
                      pop(&Top);
                  
                  break;
             }
             
             case 3:
             {
                  printf("\nThe Stack is :  ");
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
