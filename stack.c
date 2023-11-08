#include<stdio.h>
#include<limits.h>
#define max 5

int stack[max];
int top=-1;

void push(int item)
{
    if(top==max-1)
    {
        printf("\nError:overflow");
    }
    else
    {
        top=top+1;
        stack[top]=item;
        printf("\nAdded");
    }
}
int pop()
{
    int val=INT_MIN;
    if(top==-1)
    {
        printf("\nError : underflow");
    }
    else
    {
        val=stack[top];
        top=top-1;
    }
    return val;
}
//testing
void add()
{
    int num;
    printf("\nEnter the number to be added : ");
    scanf("%d",&num);
    push(num);
}
void del()
{
    int num;
    num=pop();
    if(num!=INT_MIN)
    {
        printf("\nThe deleted value is : %d",num);
    }
}
void showtop()
{
    printf("\nTOP : %d",top);
    if(top!=-1)
    {
        printf("\nValue at TOP : %d",stack[top]);
    }
}
void showstack()
{
    int i;
    printf("\nThe stack is : ");
    if(top==-1) printf("\nEmpty stack");
    for(i=top; i>=0; i--)
    {
        printf("%d\t",stack[i]);
    }
}

int main()
{
    int op;
    do
    {
        printf("\n\nStack Operations");
        printf("\n1. Push");
        printf("\n2. POP");
        printf("\n3. TOP");
        printf("\n4. Show Stack");
        printf("\n0. Exit");
        printf("\nEnter choice : ");
        scanf("%d",&op);
        if(op==0) break;
        else if(op==1) add();
        else if(op==2) del();
        else if(op==3) showtop();
        else if(op==4) showstack();
    }while(op!=0);
}
