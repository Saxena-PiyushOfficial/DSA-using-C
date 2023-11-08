#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start;
void addnode(int item)
{
    struct node *ptr1,*ptr2;
        ptr1=start;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr2=(struct node *)malloc(sizeof(struct node));
        ptr2->next=NULL;
        ptr2->info=item;
        //add new node to list
        ptr1->next=ptr2;
}

void display_list()
{
    struct node *ptr;
    printf("\nThe list is : Start->");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    printf("NULL");
}
void insert_first(int val)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->info=val;
    ptr->next=start->next;
    start->next=ptr;
}
int delete_first()
{
    int val=INT_MIN;
    struct node *ptr;
    if(start->next==NULL)
    {
        printf("list is empty");
    }
    else
    {
    val=start->next->info;
    ptr=start->next;
    start->next=ptr->next;
    free(ptr);
    }
    return val;
}
int delete_end()
{
    struct node *p,*prep;
    int val=INT_MIN;
    if(start->next==NULL)
    {
        printf("List is empty");
    }
    else{
     p=start;
    while(p->next!=NULL)
    {
        prep=p;
        p=p->next;
    }
    prep->next=NULL;
    val=p->info;
    free(p);
    }
    return val;

}
//testing
void add()
{
    int num;
    printf("Enter number : ");
    scanf("%d",&num);
    addnode(num);
    printf("\nAdded");
}
void infirst()
{
    int num;
    printf("Enter number : ");
    scanf("%d",&num);
    insert_first(num);
    printf("\nAdded to start");
}
void delfirst()
{
    int num;
    num=delete_first();
    if(num!=INT_MIN)
    {
        printf("\nThe deleted value is : %d",num);
    }
}
void delend()
{
    int num;
    num=delete_end();
    if(num!=INT_MIN)
    {
        printf("\nThe deleted value is : %d",num);
    }
}
int main()
{
    int op;
    start=(struct node *)malloc(sizeof(struct node));
    start->info=0;
    start->next=NULL;
    do
    {
        printf("\nList Operations");
        printf("\n1. Add");
        printf("\n2. Display");
        printf("\n3. Insert First");
        printf("\n4. Delete First");
        printf("\n5. Delete End");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) add();
        else if(op==2) display_list();
        else if(op==3) infirst();
        else if(op==4) delfirst();
        else if(op==5) delend();
    }while(op!=0);
}
