#include<stdio.h>
int find(int v[],int x,int n,int *c)
{
  int i;
  for(i=0;i<n;i++)
  {
      *c=*c+1;
      if(v[i]==x)
      {
          return i;
      }
  }
  return -1;
}
void main()
{
    int a[1000];
    int i,x,pos,count=0;
    for(i=0;i<1000;i++)
    {
        a[i]=i+1;
    }
    printf("The values : ");
    for(i=0;i<1000;i++)
    {
        printf("%d\t",i);
    }
    printf("\nEnter number to be searched : ");
    scanf("%d",&x);
    pos=find(a,x,1000,&count);
    printf("\nPosition : %d",pos);
    printf("\nCount : %d",count);
}
