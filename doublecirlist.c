#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct dlist
{
    int info;
    struct dlist *next;
    struct dlist *pre;
};
struct dlist *start=NULL;
void additem(int item)
{
    struct dlist *ptr1,*ptr2;
    ptr1=(struct dlist *)malloc(sizeof(struct dlist));
    ptr1->next=NULL;
    ptr1->info=item;
    if(start==NULL)
    {
        ptr1->pre=NULL;
        start=ptr1;
    }
    else
    {
        ptr2=start;
    while(ptr2->next!=NULL)
    {
        ptr2=ptr2->next;
    }
    ptr2->next=ptr1;
    ptr1->pre=ptr2;
    }
}
void insert_first(int item)
{
    struct dlist *ptr;
    ptr=(struct dlist*)malloc(sizeof(struct dlist));
    ptr->info=item;
    ptr->pre=NULL;
    if(start==NULL)
    {
        ptr->next=NULL;
        start=ptr;
    }
    else
    {
        ptr->next=start;
        start->pre=ptr;
        start=ptr;
    }
}
int del_last()
{
    struct dlist *p;
    int item=INT_MIN;
    if(start==NULL)
        printf("LIst Empty");
    else
    {
        p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    item=p->info;
    p->pre->next=NULL;
    free(p);
    }
   return item;
}
int del_first()
{
    struct dlist *p;
    int item=INT_MIN;
    if(start==NULL)
        printf("List empty");
    else
    {
     p=start;
    item=p->info;
    start=start->next;
    start->pre=NULL;
    free(p);
    }
    return item;
}
void show()
{
    struct dlist *p;
    p=start;
    printf("START->");
    while(p!=NULL)
    {
        printf("%d->",p->info);
        p=p->next;
    }
    printf("NULL");
}
void main()
{
    int n,op;
    do
    {
        printf("\nDouble Linked List\n");
        printf("1.Add\n");
        printf("2.Add_First\n");
        printf("3.Delete First\n");
        printf("4.Delete End\n");
        printf("5.Show\n");
        printf("0.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&op);
        if(op==0)break;
        else if(op==1)
        {
        printf("\nEnter item");
        scanf("%d",&n);
        additem(n);
        }
        else if(op==2)
        {
        printf("Enter item");
        scanf("%d",&n);
        insert_first(n);
        }
        else if(op==3)
        {
        n=del_first();
        printf("Item delete %d",n);
        }
        else if(op==4)
        {
        n=del_last();
        printf("Item delete %d",n);
        }
      else if(op==5)show();
    }while(1);
}
