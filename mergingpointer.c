#include<stdio.h>
#include<stdlib.h>
void input(int *x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
     printf("Enter the of elements of array:");
     scanf("%d",&x[i]);
    }
}
void display(int *x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
     printf("%d ",x[i]);
    }
}
void merging(int *A[],int M,int *B[],int *V[],int N)
{
    int i=0,j=0,k=0;
    while(i<M && j<N)
    {

        if(A[i]<B[j])
        {
            V[k]=A[i];
            k=k+1;
            i=i+1;
        }
        else
        {
            V[k]=B[j];
            k=k+1;
            j=j+1;
        }
    }
    while(i<M)
    {

        V[k]=A[i];
        k=k+1;
        i=i+1;
    }
    while(j<N)
    {
        V[k]=B[j];
        k=k+1;
        j=j+1;
    }
}
void main()
{
    int i,*A,*B,V,M,N;
   printf("Enter the no. of elements of A array:");
  scanf("%d",&M);
  A=(int*)malloc(M*sizeof(int));
   printf("Enter the no. of elements of B array:");
  scanf("%d",&N);
  B=(int*)malloc(N*sizeof(int));
  V=(int*)malloc((M+N)*sizeof(int));
  input(A,M);
  printf("\n");
  input(B,N);
   printf("\nArray A\n");
  display(A,M);
   printf("\nArray B\n");
  display(B,N);
    merging(A,M,B,V,N);
     printf("\nArray V\n");
    display(V,M+N);

}
