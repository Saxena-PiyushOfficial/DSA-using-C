namespace std;
#include<stdio.h>
#include<iostream.h>
public void shell_sort(int x[],int n)
{
   int gap,i,j,temp;
   for(gap=n/2;gap>0;gap/=2)
   {
       for(i=gap;i<n;i++)
       {
           for(j=i-gap;j>=0 && x[j]>x[j+gap];j=j-gap)
           {
               temp=x[j];
               x[j]=x[j+gap];
               x[j+gap]=temp;
           }
       }
   }
}
void main()
{
    int A[]={2,8,4,5,9},n=5,i;
    shell_sort(A,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }

}
