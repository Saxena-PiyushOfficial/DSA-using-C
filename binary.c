#include<stdio.h>
int find(int v[],int x,int n,int *c)
{
  int low=0;
  int high=n-1;
  int mid;
  while(low<=high)
  {
      *c=*c+1;
      mid=(low+high)/2;
      if(x<v[mid])
      {
          high=mid-1;
      }
      else if(x>v[mid])
      {
          low=mid+1;
      }
      else
      return mid;
  }
  return -1;
}
void main()
{
    int i,a[500],x,pos,count=0;
    for(i=0;i<500;i++)
    {
        a[i]=i+1;
    }
    for(i=0;i<500;i++)
    {
        printf("%d\t",i);
    }
    printf("Enter the number to search:\n");
    scanf("%d",&x);
    pos=find(a,x,500,&count);
    printf("%d\n",pos);
    printf("%d",count);

}
