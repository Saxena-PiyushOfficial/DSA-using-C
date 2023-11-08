#include<stdio.h>
void display(int[],int);
void Insertion_sort(int[],int);
void main()
{
    int n=8;
   //int p[]={25,57,48,37,12,92,26,33};
    int p[]={12,25,26,33,37,48,57,92};
    //int p[]={5,6,8,9,10,14,15,90};
    //int p[]={15,13,12,11,10,8,6,4};


    display(p,n);
    printf("\nThe sorted array through Insertiom sort:\n");
    Insertion_sort(p,n);
    display(p,n);
}
void display(int v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
}
void Insertion_sort(int x[],int n)
{
   int i,k,y;
   int count=0;
   for(k=1;k<n;k++)
   {
       y=x[k];
       for(i=k-1;i>=0 && y<x[i];i--)
       {
           count++;
           x[i+1]=x[i];
       }
       x[i+1]=y;
   }
      printf("\ncount=%d\n",count);
}

