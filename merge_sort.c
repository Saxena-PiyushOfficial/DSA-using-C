#include<stdio.h>
void merge_sort(int x[],int n)
{
    int a[n];
    int i,j,k,size=1;
    int l1,l2,u1,u2;
    while(size<n)
    {
        l1=0;
        k=0;

        while((l1+size)<n)
        {

            l2=l1+size;
            u1=l2-1;
            u2=(l2+size-1<n)?l2+size-1:n-1;
            for(i=l1,j=l2;i<=u1 && j<=u2;k++)
            {
                if(x[i]<x[j])
                {
                    a[k]=x[i++];
                }
                else
                {
                   a[k]=x[j++];
                }
            }
            while(i<=u1)
            {
                a[k++]=x[i++];
            }
            while(j<=u2)
            {
                a[k++]=x[j++];
            }
            l1=u2+1;
        }
        for(i=l1;k<n;i++)
           a[k++]=a[i];
        for(i=0;i<n;i++)
            x[i]=a[i];

        size=size*2;
    }
}
void main()
{
    int i;
    int A[]={25,57,48,37,12,86,99,67,23,20};
    merge_sort(A,10);
    for(i=0;i<10;i++)
        printf("%d\t",A[i]);
}
