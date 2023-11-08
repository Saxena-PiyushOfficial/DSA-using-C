#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;

};
struct node *front=NULL,*rear=NULL;
void addqueue(int item)
{
  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  p->data=item;
  p->next=NULL;
  if(front==NULL && rear==NULL)
  {
     front=p;
     rear=p;
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
  int item=INT_MAX;
  p=(struct node*)malloc(sizeof(struct node));
  if(front==NULL)
   printf("The queue is Empty");
  else
  {
    item=front->data;
    p=front;
    front=front->next;
    free(p);
  }
  return item;
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
//testing
void add()
{
  int num;
  printf("Enter the number:\n");
  scanf("%d",&num);
  addqueue(num);
  printf("\nADDED");
}
void Delete()
{
  int num;
  num=deletequeue();
  printf("\nThe deleted number is %d",num);
}
int main()
{
  int op;
  do
  {
  printf("\nLinked list Queue Operation");
  printf("\n1.Add");
  printf("\n2.Delete");
  printf("\n3.Display");
  printf("\n0.EXIT");
  printf("\nEnter your Choice:\n");
  scanf("%d",&op);
  if(op==0)break;
  else if(op==1)add();
  else if(op==2)Delete();
  else if(op==3)display();
}while(op!=0);
}
