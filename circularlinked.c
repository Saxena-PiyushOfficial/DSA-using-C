#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
  int info;
  struct node *next;
};
struct node *start=NULL;
void addlist(int item)
{
    struct node *ptr1,*ptr2;
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->info=item;
        start->next=start;
    }
    else
    {
        ptr1=start;
        while(ptr1->next!=start)
        {
            ptr1=ptr1->next;
        }
        ptr2=(struct node*)malloc(sizeof(struct node));
        ptr1->next=ptr2;
        ptr2->next=start;
        ptr2->info=item;
    }
}
void insert_first(int item)
{
    struct node *ptr,*ptr1;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=item;
    if(start==NULL)
   {
        ptr->next=ptr;
        start=ptr;
   }
   else
   {
       ptr->next=start;
       ptr1=start;
       while(ptr1->next!=start)
       {
           ptr1=ptr1->next;
       }
       ptr1->next=ptr;
       start=ptr;
   }
}
int del_first()
{
    struct node *ptr1,*ptr2;
    int val=INT_MIN;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else if(start->next==start)
    {
        val=start->info;
        free(start);
        start=NULL;
    }
    else
    {
        val=start->info;
        ptr2=start;
        ptr1=start;
        while(ptr1->next!=start)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=start->next;
        free(ptr2);
        start=ptr1->next;
    }
    return val;
}
int del_last()
{
    struct node *p,*prep;
    int val=INT_MIN;
    if(start==NULL)
        printf("\nInvalid");
    else if(start->next==start)
    {
        val=start->info;
        free(start);
        start=NULL;
    }
    else
    {
      p=start;
    while(p->next!=start)
    {
        prep=p;
        p=p->next;
    }
    prep->next=start;
    val=p->info;
    free(p);
    }
    return val;

}
void display()
{
    struct node *p;
    p=start;
    if(p==NULL)
    {
        printf("\nstart->NULL");
    }
    else
    {
        printf("start->");
        while(p->next!=start)
        {
            printf("%d->",p->info);
            p=p->next;
        }
        printf("%d->",p->info);
        printf("start");
    }
}
void add()
{
    int num;
    printf("enter the number to add:\n");
    scanf("%d",&num);
    addlist(num);
    printf("\n\nADDED");
}
void infirst()
{
    int num;
    printf("Enter the number :\n");
    scanf("%d",&num);
    insert_first(num);
    printf("\nADDED");
}
void defirst()
{
    int num;
    num=del_first();
    if(num!=INT_MIN)
    printf("\nthe deleted number is %d",num);
}
void delast()
{
    int num;
    num=del_last();
    if(num!=INT_MIN)
    printf("\nthe deleted number is %d",num);
}
void main()
{
     int op;
    do
    {
        printf("\n\nCircular List Operations");
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. Delete First");
        printf("\n4. Insert first");
        printf("\n5. Delete last");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) add();
        else if(op==2) display();
        else if(op==3) defirst();
        else if(op==4) infirst();
        else if(op==5) delast();
    }while(op!=0);
}
