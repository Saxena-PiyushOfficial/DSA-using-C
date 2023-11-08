#include<stdio.h>
void input(int[],int);
void display(int[],int);
void Bubble_sort(int[],int);
void main()
{
    int n=8;
   //int p[]={25,57,48,37,12,92,26,33};
    int p[]={12,25,26,33,37,48,57,92};
   // int p[]={5,6,8,9,10,14,15,90};
   // int p[]={15,13,12,11,10,8,6,4};

    display(p,n);
    printf("\nThe sorted array through Bubble sort:\n");
    Bubble_sort(p,n);
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
void Bubble_sort(int x[],int n)
{
    int temp,j,pass,flag=1;
    int count=0;
    for(pass=0;pass<n-1 && flag==1;pass++)
    {
        flag=0;
        for(j=0;j<n-pass-1;j++)
        {
            count++;
            if(x[j]>x[j+1])
            {
                 flag=1;
                 temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
    printf("\ncount=%d\n",count);
}
