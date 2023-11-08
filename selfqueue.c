#include<stdio.h>
#define Max 8
int Queue[Max];
int Front=-1;
int Rear=-1;
void addqueue(int item)
{
    if((Front==0 && Rear==Max-1)||(Rear+1==Front))
    {
        printf("Queue Overflow\n");
    }
    else
        {
            if(Rear==-1)
            {
                Front=0;
                Rear=0;
            }
            else if(Rear==Max-1)
            {
                Rear=0;
            }
            else
            {
                Rear=Rear+1;
            }
            Queue[Rear]=item;
        }
}
int deletequeue()
{
    int x=-1;
    if(Front==-1)
        printf("Queue Underflow\n");
    else
    {
        x=Queue[Front];
        if(Front==Max-1)
        {
            Front=0;
        }
        else if(Front==Rear)
        {
            Front=Rear=-1;
        }
        else
        {
            Front=Front+1;
        }
    }
    return x;
}
void A()
{
    int num;
    printf("Enter the Number to add:\n");
    scanf("%d",&num);
    addqueue(num);
    printf("\nNumber is added\n");
}
void B()
{
    int num;
    num=deletequeue();
    if(num!=-1)
        printf("\nThe number deleted is %d\n",num);
}
void C()
{
    printf("The Front is=%d\n",Front);
    printf("The Rear is=%d",Rear);
}
void D()
{
    int i;
    if(Front!=-1)
        for(i=Front;i<Rear;i++)
        printf("%d\t",Queue[i]);
    if(Rear<Front)
    {
        for(i=Front;i<Max;i++)
            printf("%d\t",Queue[i]);
       for(i=0;i<Rear;i++)
        printf("%d\t",Queue[i]);
    }
}
void main()
{
    int i;
    do
    {
     printf("QUEUE OPERATION\n");
     printf("1.Add to Queue\n");
     printf("2.Delete from Queue\n");
     printf("3.FRONT and REAR position\n");
     printf("4.Display Queue\n");
     printf("0.Exit\n");
     printf("Enter your Choice\n");
     scanf("%d",&i);
     if(i==0)
        break;
     else if(i==1)
        A();
     else if(i==2)
        B();
      else if(i==3)
        C();
         else if(i==4)
        D();
    printf("\n************************\n");
    }while(i!=0);
}
