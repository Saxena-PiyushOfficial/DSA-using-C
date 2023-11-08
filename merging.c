#include<stdio.h>
void merging(int A[],int M,int B[],int V[],int N)
{
    int i=0,j=0,k=0;
    while(i<M && j<N)
    {
        if(A[i]<B[j])
        {
            V[k]=A[i];
            k++;
            i++;
        }
        else
        {
            V[k]=B[j];
            k++;
            j++;
        }
    }
    while(i<M)
    {

        V[k]=A[i];
        k++;
        i++;
    }
    while(j<N)
    {

        V[k]=B[j];
        k++;
        j++;
    }

}
void main()
{
    int i;
    int A[]={1,5,10,11,15,40,45},M=7;
    int B[]={8,13,17},N=3;
    int V[M+N];
    merging(A,M,B,V,N);
    for(i=0;i<M+N;i++)
    {
        printf("%d ",V[i]);
    }
}
