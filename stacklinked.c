#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int item)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=top;
    top=ptr;
}
int pop()
{
    int val=INT_MIN;
    struct node *p;
    if(top==NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
          val=top->data;
          p=top;
          top=top->next;
          free(p);
    }
    return val;
}
void display()
{
    struct node *ptr;
    ptr=top;
       printf("Top->");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}
void add()
{
    int num;
    printf("Enter the num:");
    scanf("%d",&num);
    push(num);
    printf("\nNumber added");
}
int Delete()
{
    int num;
    num=pop();
    if(num!=INT_MIN)
    printf("\nThe deleted number is %d",num);
}
void main()
{
     int op;
    do
    {
        printf("\n\nList Operations");
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. Delete");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) add();
        else if(op==2) display();
        else if(op==3) Delete();
    }while(op!=0);
}
