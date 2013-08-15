#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct queue
{
        int data[MAX];
        int front, rear;
}queue;

init(queue *q)
{
    q->front=q->rear=-1;               
}

int empty(queue *q)
{
    if(q->rear==-1)
         return(1);
    return(0);
}

int full(queue *q)
{
    if(q->rear==MAX-1)
           return(1);
    return(0);
}

void InsertQueue(queue *q,int x)
{
     if(!full(q))
     {
          if(empty(q))
          {
                q->rear=q->front=0;
                q->data[q->rear]=x;   
          }
          
          else
          {
              q->rear++;   
              q->data[q->rear]=x;
          }      
     }     
     else
     {
          printf("\nQueue is full\n");    
     }

}

int deleteQueue(queue *q)
{
    int x=q->data[q->front];;
    if(!empty(q))
    {
         if(q->front==q->rear)
         {
             q->rear=q->front=-1;
             //init(&q);
         }          
         else
         {
             q->front++;
             return x;    
         }
    }
    else
    {
        printf("\nQueue is empty\n");
        return ('\0');
    }
}

void display(queue *q)
{
     int i;
     for(i=q->front;i<=q->rear;i++)
     {
           printf("\t%d",q->data[i]);
     }
}


int main()
{
     queue Q;
     int i,j,x,choice;
     init(&Q);
     do{
         printf("\n\nEnter 1 to Insert \n");
         printf("Enter 2 to delete \n");
         printf("Enter 3 to display \n");
         printf("Enter 4 to exit \n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             {
                  printf("Enter the data to be inserted: ");
                  scanf("%d",&x);
                  InsertQueue(&Q,x);
                  break;
             }
             
             case 2:
             {
                  x=deleteQueue(&Q);
                  if(x!=0)
                       printf("\nElement deleted is :  %d ",x);
                  break;
             }
             
             case 3:
             {
                  printf("\nThe Queue is \n\n");
                  display(&Q);
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
