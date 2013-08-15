#include<stdio.h>
#include<conio.h>

typedef struct pnode 
{
       float coeff;
       int pow;
       struct pnode *next;       
}pnode;

pnode *create(int n)
{
      pnode *head,*P;
      int i;
      head=(pnode*)malloc(sizeof(pnode));
      P=head;
      printf("\nEnter Coefficient its power : \n");
      scanf("%f %d",&(P->coeff),&(P->pow));
      for(i=1;i<n;i++)
      {
             P->next=(pnode*)malloc(sizeof(pnode));
             P=P->next;
             printf("\nEnter next Coefficient its power : \n");
             scanf("%f%d",&(P->coeff),&(P->pow));
             P->next=NULL;                
      }
      return head;
}

void display(pnode *head)
{
     printf("\nEntered Polynomial  :  ");
     while(head!=NULL)
     {
             printf("%5.2fx^%d",(head->coeff),(head->pow));      
             if(head->next!=NULL)
                   printf(" + ");
             head=head->next;          
     }     
}


int main()
{
    pnode * Head;
    int n;
    printf("Enter Number of terms in Polynomial : ");
    scanf("%d",&n);
    Head=create(n);
    display(Head);
    getch();
}




