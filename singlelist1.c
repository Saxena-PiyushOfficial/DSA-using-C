#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int info;
    struct node*next;
};
struct node *start=NULL;
void addlist(int item)
{
    struct node *p1,*p2;
    if(start==NULL)
    {
        start=(struct node *)malloc(sizeof(struct node));
        start->info=item;
        start->next=NULL;
    }
    else
    {
     //set p1 to last node
     p1=start;//copying start to p1
    while(p1->next!=NULL)
    {
        p1=p1->next;
    }
    p2=(struct node *)malloc(sizeof(struct node));
    p2->next=NULL;
    p2->info=item;
    p1->next=p2;
    }
}
void Display()
{
    struct node *ptr;
    printf("\nThe list is:Start->");
    ptr=start;
    while(ptr!=NULL)
    {
    printf("%d->",ptr->info);
    ptr=ptr->next;
    }
    printf("NULL");
}
void Infirst(int val)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=val;
    p->next=start;
    start=p;
}
int delfirst()
{
    int val=INT_MIN;
    struct node *p;
    if(start==NULL)
    {
        printf("\nInvalid Operation as the list is empty");
    }
    else
    {
      val=start->info;
          p=start;
          start=start->next;
          free(p);
    }
    return val;
}
int Delend()
{
    struct node *p,*prep;
    int val=INT_MIN;
    if(start==NULL)
    {
        printf("\nInvalid");
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            prep=p;
            p=p->next;
        }
        prep->next=NULL;
        val=p->info;
        free(p);
        return val;
    }
}
void add()
{
    int num;
    printf("Enter the num:\n");
    scanf("%d",&num);
    addlist(num);
    printf("\nADDED\n");
}
void Insert_first()
{
    int num;
    printf("Enter the num:\n");
    scanf("%d",&num);
    Infirst(num);
    printf("\nInsertation successfully\n");
}
int Delete_first()
{
    int num;
    num=delfirst();
    if(num!=INT_MIN)
    {
       printf("deleted number is %d",num);
    }
}
int Delete_end()
{
 int num;
    num=Delend();
    if(num!=INT_MIN)
    {
       printf("deleted number is %d",num);
    }
}
void main()
{
    int op;
    do
    {
        printf("\nLinked list Operation\n");
        printf("\n1.Add");
        printf("\n2.Insert First");
        printf("\n3.Delete First");
        printf("\n4.Delete End");
        printf("\n5.Display");
        printf("\n0.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&op);
        if(op==0)
            break;
        else if(op==1)
            add();
        else if(op==2)
            Insert_first();
        else if(op==3)
            Delete_first();
        else if(op==4)
            Delete_end();
        else if(op==5)
            Display();
            printf("\n**********Thank You**********");
    }while(1);
}
