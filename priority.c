#include<stdio.h>
#include<stdlib.h>
struct pqueue
{
    int info;
    int pr;
    struct pqueue *next;
};
struct pqueue *front=NULL;
void add(int item,int p)
{
    struct pqueue *ptr,*q;
    ptr=(struct pqueue *)malloc(sizeof(struct pqueue));
    ptr->info=item;
    ptr->pr=p;
    ptr->next=NULL;
    if(front==NULL||p>front->pr)
    {
        ptr->next=front;
        front=ptr;
    }
    else
    {
        q=front;
        while(q->next!=NULL && q->next->pr>=p)
        {
            q=q->next;
        }
        ptr->next=q->next;
        q->next=ptr;
    }
}
int del()
{
    struct pqueue *ptr;
    int item=-1;
    if(front==NULL)
        printf("Error");
        else if(front->next==NULL)
        {
            item=front->info;
            ptr=front;
            front=front->next;
            free(ptr);

        }
    else
    {
        item=front->info;
        ptr=front;
        front=front->next;
        free(ptr);
    }
    return item;
}
void additem()
{
    int num,p;
    printf("Enter the num and priority\n");
    scanf("%d%d",&num,&p);
    add(num,p);
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

