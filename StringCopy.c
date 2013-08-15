#include<stdio.h>
#include<conio.h>

int main()
{
    char *p,*q;
    char x;
    printf("Enter the String p : ");
    
    while(x=getchar()!='\n')
    {
          *p=x; 
          p++;                
    } 
     
    printf("Entered String is : ");
    
    while(*p!='\0')
    {
          printf("%c",*p);
          p++;               
    }
    
    //while(*s++ = *t++)
    while(*p)
    {
         *p = *q;
         p++;
         q++; 
    }
    *p = *q;
}
