// show even number series
#include<stdio.h>
void main()
{
     int num,i,even,odd;
     printf("enter the number");
     scanf("%d",&num);
     for(i=1;i<=num;i++);
     {
         if(num%2==0)
         {
             even ;
         }
         else
         {
             odd ;
         }
     }
     printf(" even=%d",even);
}
