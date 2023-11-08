#include<stdio.h>
void display(int[],int);
void Selection_sort(int[],int);
void main()
{
    int n=8;
   //int p[]={25,57,48,37,12,92,26,33};
   int p[]={12,25,26,33,37,48,57,92};

    //int p[]={5,6,8,9,10,14,15,90};
   //int p[]={15,13,12,11,10,8,6,4};


    display(p,n);
    printf("\nThe sorted array through Selectiom sort:\n");
    Selection_sort(p,n);
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
void Selection_sort(int x[],int n)
{
    int i,large,index,j;
    int count=0;
    for(i=n-1;i>0;i--)
    {
        large=x[0];
        index=0;
        for(j=1;j<=i;j++)
        {
            count++;
            if(x[j]>large)
            {
                large=x[j];
                index=j;
            }
        }
        x[index]=x[i];
        x[i]=large;
    }
    printf("Count=%d\n",count);
}

