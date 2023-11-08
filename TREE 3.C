/*Non recursive postorder traversal of binary tree*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
struct tnode
{
	int val;
	struct tnode *left;
	struct tnode *right;
};

struct stack
{
	int top;
	struct tnode *item[MAX];
};

struct tnode * addnode(struct tnode *,int);
void print_tnode(struct tnode *);


void init(struct stack *p);
int isfull(struct stack *p);
int isempty(struct stack *p);
void push(struct stack *p,struct tnode *q);
struct tnode *pop(struct stack *p);


int main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	char ch='y';
	q=NULL;

	p=NULL;
	while(ch=='y' || ch=='Y')
	{
		printf("Enter the number to be added :");
		scanf("%d",&num);
		fflush(stdin);
		p=addnode(p,num);
		printf("Do you want to add more elements to tree y/n : ");
		ch=getchar();
		fflush(stdin);
	}
	print_tnode(p);
	getch();
}
struct tnode * addnode(struct tnode *p,int num)
{
	if(p==NULL)
	{
		p=(struct tnode *)malloc(sizeof(struct tnode));
		p->val=num;
		p->left=NULL;
		p->right=NULL;
	}
	else if(num<p->val)
		p->left=addnode(p->left,num);
	else
		p->right=addnode(p->right,num);
	return p;
}
void print_tnode(struct tnode *p)
{
	struct tnode *q;
	struct stack *s;
	init(s);
	q=p;

	while(1) /*infinite loop*/
	{
		if(q!=NULL)
		{
			push(s,q);
			q=q->left;
		}
		else
		{
			if(isempty(s))
				return;
			q=pop(s);
			q=q->right;

		}

	}
}
void init(struct stack *p)
{
	p->top=-1;
}
int isfull(struct stack *p)
{
	if(p->top>=MAX-1)
		return 1;
	else
		return 0;
}
int isempty(struct stack *p)
{
	if(p->top<0)
		return 1;
	else
		return 0;
}
void push(struct stack *p,struct tnode *q)
{
	if(isfull(p))
	{
		printf("Overflow");
		exit(1);
	}
	p->top++;
	p->item[p->top]=q;
}
struct tnode *pop(struct stack *p)
{
	if(isempty(p))
	{
		printf("Unerflow");
		exit(1);
	}
	return p->item[p->top--];
}
