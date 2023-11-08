#include<stdio.h>
#define max 8
int queue[max];
int FRONT=-1,REAR=-1;
void addqueue(int item)
{
    if((FRONT==0 && REAR==max-1)||(REAR+1==FRONT))
        printf("Overflow");
    else
    {
        if(REAR==-1)
        {
            FRONT=0;
            REAR=0;
        }
        else if(REAR==max-1)
        {
            REAR=0;
        }
        else
        {
            REAR=REAR+1;
        }
        queue[REAR]=item;
    }
}
int deletequeue()
{
    int item=-1;
    if(FRONT==-1)
    {
        printf("Underflow");
    }
    else
    {
        item=queue[FRONT];
        if(FRONT==REAR)
        {
            FRONT=REAR=-1;
        }
    else if(FRONT==max-1)
        FRONT=0;
    else
    {
        FRONT=FRONT+1;
    }
}
return item;
}
void A();
void B();
void C();
void D();
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
void A()
{
    int num;
     printf("Enter the number to be added:");
     scanf("%d",&num);
     addqueue(num);
     printf("\n\nAdded\nPress any key to continue");
}
void B()
{
    int num;
    num=deletequeue();
    if(num!=-1)
        printf("The number %d had deleted",num);

        printf("\n\nPress any key to continue");
}
void C()
{
    printf("FRONT=%d",FRONT);
    printf("REAR=%d",REAR);

    printf("\n\nPress any key to continue");
}
void D()
{
    int i;
    if(FRONT!=-1)
    {
        for(i=FRONT;i<=REAR;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    if(REAR<FRONT)
    {
        for(i=0;i<REAR;i++)
        {
            printf("%d\t",queue[i]);
        }
        for(i=FRONT;i<max;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
    printf("\n\nPress any key to continue");
}
