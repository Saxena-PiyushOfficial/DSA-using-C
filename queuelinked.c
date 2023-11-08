#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *front=NULL,*rear=NULL;
void addqueue(int item)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->next=NULL;
    p->data=item;
    if(front==NULL && rear==NULL)
    {
        rear=p;
        front=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
}
int deletequeue()
{
    struct node *p;
   int val=INT_MIN;
   if(front==NULL)
    printf("Stack is empty");
   else
   {
   val=front->data;
   p=front;
   front=front->next;
   free(p);
   }
   return val;
}
void display()
{
    struct node *p;
    p=front;
    printf("Front->");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL");
}
void add()
{
    int num;
    printf("Enter the num:\n ");
    scanf("%d",&num);
    addqueue(num);
    printf("\nADDED\n");

}
void Delete()
{
    int num;
    num=deletequeue();
    if(num!=INT_MIN)
    {
        printf("\nDeleted number is %d",num);
    }
}
void main()
{
 int op;
    do
    {
        printf("\nList Operations");
        printf("\n1.Add");
        printf("\n2.Delete");
        printf("\n3.Display ");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) add();
        else if(op==3) display();
        else if(op==2) Delete();
    }while(op!=0);
}
