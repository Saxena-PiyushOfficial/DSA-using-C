#include<stdio.h>
#define Max 5
int Queue[Max];
int Front=-1,Rear=-1;
void addqueue(int item)
{
    if((Front==0 && Rear==Max-1)||Rear+1==Front)
       printf("Overflow");
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
int Delete()
{
    int x=-1;
    x=Queue[Front];
    if(Front==-1)
    printf("\nUnderflow\n");
    else
    {
        if(Front==Rear)
        Front=Rear=-1;
        else if(Front==Max-1)
        Front=0;
        else
            {
            Front=Front+1;
            }
    }
    return x;
}
void A();
void B();
void C();
void D();
void main()
{
    int op;
    do
    {
        printf("Queue Opetation\n");
        printf("1.Add\n");
        printf("2.Delete\n");
        printf("3.Front and Rear Position\n");
        printf("4.Display\n");
        printf("0.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&op);
        if(op==0)
            break;
        else if(op==1)
            A();
        else if(op==2)
            B();
        else if(op==3)
            C();
            else if(op==4)
            D();
        printf("\n-----------Thank You----------\n");
    }while(op!=0);
}
void A()
{
    int num;
    printf("Enter the number to be added\n");
    scanf("%d",&num);
    addqueue(num);
    printf("ADDED");
}
void B()
{
    int item;
    item=Delete();
    if(item!=-1)
    printf("The deleted item is %d",item);
}
void C()
{
    printf("Front: %d",Front);
    printf("Rear: %d",Rear);
}

void D()
{
    int i;
    printf("\nThe queue is : ");
    if(Front==-1 || Rear==-1)
    {
        printf("\nEmpty queue");
    }
    else if(Front<=Rear)
    {
       for(i=Front;i<=Rear;i++)
       {
           printf("%d\t",Queue[i]);
       }
    }
    else
    {
        for(i=Front;i<Max;i++)
        {
            printf("%d\t",Queue[i]);
        }
        for(i=0;i<=Rear;i++)
        {
            printf("%d\t",Queue[i]);
        }
    }
}
