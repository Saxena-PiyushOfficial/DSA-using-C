#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
struct node
{
int info;
struct node *pre;
struct node *next;
};
struct node *start=NULL;
void additem(int item)
{
    struct node *ptr,*ptr1;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=item;
    ptr->next=start;
    if(start==NULL)
    {
       ptr->next=ptr;
       ptr->pre=ptr;
       start=ptr;
    }
    else
    {
    ptr1=start;
    while(ptr1->next!=start)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=ptr;
    ptr->pre=ptr1;
    start->pre=ptr;
    }
}
void insert_first(int item)
{
    struct node *ptr,*p;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=item;
    if(start==NULL)
    {
        ptr->next=ptr;
        ptr->pre=ptr;
        start=ptr;
    }
    else
    {
      ptr->next=start;
      p=start;
      while(p->next!=start)
      {
          p=p->next;
      }
      ptr->pre=p;
      p->next=ptr;
      start=ptr;
    }
}
int delete_first()
{
    int item=INT_MIN;
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if(start->next==start)
    {
        item=start->info;
        free(start);
        start=NULL;
    }
    else
    {
        item=start->info;
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=start->next;
        start->next->pre=ptr;
        free(start);
        start=ptr->next;
    }
    return item;
}
int delete_last()
{
    int x=INT_MIN;
   struct node *prep,*ptr;
if(start==NULL)
    printf("\nUnderflow");
else if(start->next==start)
 {
     x=start->info;
     free(start);
     start=NULL;
 }
else
{
  ptr=start;
 while(ptr->next!=start)
 {
     prep=ptr;
     ptr=ptr->next;
 }
   x=ptr->info;
   prep->next=start;
   start->pre=prep;
   free(ptr);
 }
return x;
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
    additem(num);
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
void delfirst()
{
    int num;
    num=delete_first();
    if(num!=INT_MIN)
    {
        printf("\nThe deleted number is %d",num);
    }
}
void dellast()
{
    int num;
    num=delete_last();
    if(num!=INT_MIN)
    {
        printf("\nThe deleted number is %d",num);
    }
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
        else if(op==3) delfirst();
        else if(op==4) infirst();
        else if(op==5) dellast();
    }while(op!=0);
}
