#include<stdio.h>
#include<conio.h>
#define MAX 100

typedef struct node 
{
       int data;
       struct node *next;       
}node;

node *create(int arr[],int n)
{
      node *head,*P;
      int i;
      head=(node*)malloc(sizeof(node));
      P=head;
      P->data = arr[0];
      P->next = NULL;
      for(i=1;i<n;i++)
      {
             P->next=(node*)malloc(sizeof(node));
             P=P->next;
             P->data=arr[i];
             P->next=NULL;                
      }
      return head;
}

void display_array(int arr[],int n)
{
     int i=0;
     while(i<n)
     {
          printf("%d ",arr[i]);
          i++;       
     }   
}

void display_list(node *head)
{
     while(head!=NULL)
     {
            printf("%d  ",(head->data));
            head=head->next;           
     }
}

int main()
{
     int arr[MAX];
     node *Head;
     int i,n;
     printf("Enter the number of elements  :  ");
     scanf("%d",&n);
     printf("Enter array elements \n");
     for(i=0;i<n;i++)
         scanf("%d",&arr[i]);
         
     printf("\nThe Array : \n");
     display_array(arr,n);
     
     Head=create(arr,n);
               
     printf("\nThe Linked list \n");
     display_list(Head);
     getch();
     return 0;
}


