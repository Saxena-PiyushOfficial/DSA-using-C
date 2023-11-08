#include<stdio.h>
#include<stdlib.h>
struct pqueue
{
 int info;
 int pr;
 struct pqueue *next;
};
struct pqueue *front=NULL;
void addqueue(int num,int prio)
{
  struct pqueue *p,*q;
  p=(struct pqueue*)malloc(sizeof(struct pqueue));
  p->info=num;
  p->pr=prio;
  p->next=NULL;
  if(front==NULL || prio>front->pr)
  {
    p->next=front;
    front=p;
  }
  else
  {
  q=front;
  while(q->next!=NULL && q->next->pr>=prio)
  {
    q=q->next;
  }
  p->next=q->next;
  q->next=p;
  }
}
int del()
{
 int item=-1;
 struct pqueue *ptr;
 if(front==NULL)
 printf("\nInvalid Deletion");
 else
 {
 item=front->info;
 ptr=front;
 front=front->next;
 }
 return item;
}
void display()
{
    struct pqueue *p;
    p=front;
    printf("THE PRIORITY QUEUE DISPLAY:");
    printf("FRONT->");
    while(p->next!=NULL)
    {
        printf("%d:%d",p->info,p->pr);
        p=p->next;
    }
    printf("NULL");
}
void additem()
{
    int num,p;
    printf("Enter the num and priority\n");
    scanf("%d%d",&num,&p);
    addqueue(num,p);
    printf("Item added");
}
void deleteitem()
{
    int num;
    num=del();
    if(num!=-1)
        printf("\nThe deleted number is %d",num);
}
void show()
{
    struct pqueue *ptr1=front;
    printf("\nThe queue is:\n");
    printf("FRONT->");
    while(ptr1!=NULL)
    {
        printf("%d:%d->",ptr1->info,ptr1->pr);
        ptr1=ptr1->next;
    }
    printf("NULL");
}
void main()
{
 int op;
    do
    {
        printf("\nPriority Operations");
        printf("\n1.Add");
        printf("\n2.Delete");
        printf("\n3.Show");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) additem();
        else if(op==3) show();
        else if(op==2) deleteitem();
    }while(op!=0);
}


