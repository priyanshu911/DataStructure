#include<stdio.h>
#include<conio.h>
#define MAX 10

typedef struct node
{
        int data;
        struct node *next;       
}node;

typedef struct queue
{
        node *front;
        node *rear;
}queue;

void init(queue *P)
{
     P->rear=NULL;      //make the queue empty
     P->front=NULL;
}

int empty(queue *P)
{
    if(P->rear==NULL)
         return (1);
    return (0);
}


void InsertQueue(queue *q,int x)
{
     node *P;
     P=(node*)malloc(sizeof(node));
     P->data = x;
     P->next = NULL;
     if(empty(q))
     {
          q->rear= P;
          q->front=P;   
     }
          
     else
     {
          (q->rear)->next=P;   
           q->rear=P;
     }  
}


int deleteQueue(queue *q)
{
        int x=-1;
        node *P;
        if(!empty(q))
        {
			P=q->front;
			x=P->data;
			if(q->front==q->rear)      //deleting last element
					 init(q);
			else
					 q->front=P->next;
			free(P);
		}
        return x;        
}


void display(queue *q)
{
     int i;
     node *P;
     P=q->front;
     while (P!=NULL)
     {
	      printf("%d  ",P->data);
	      P=P->next;
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
