/*Program to count the total no of nodes and levels*/
/*Depth of left sub tree and right subtree*/
/*Total nodes in left subtree and right subtree*/
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
	int a,b,c,d;
	int e,f;
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
	a=count_levels(p);
	printf("\n Total no of levels(depth) in tree are %d",a);
	b=count_nodes(p);
	printf("\n Total no of nodes in tree are %d",b);
	c=count_levels(p->left);
	printf("\n Depth of left sub tree is %d",c);
	d=count_levels(p->right);
	printf("\n Depth of right sub tree is %d",d);
	e=count_nodes(p->left);
	printf("\n Total no of nodes in left sub tree are %d",e);
	f=count_nodes(p->right);
	printf("\n Total no of nodes in right sub tree are %d",f);
	
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


int count_levels(struct tnode *p)
{
	/*non recursive inorder traversal*/
	struct tnode *q;
	struct stack *s;
	int a=0;
	init(s);
	q=p;

	do
	{
		while(q!=NULL)
		{
			push(s,q);
			q=q->left;
		}
		if(s->top>a)
			a=s->top;
		if(!isempty(s))
		{
			q=pop(s);
			q=q->right;
		}
	}while(!isempty(s) || q!=NULL);
	return (a==0)?0:++a;
}


int count_nodes(struct tnode *p)
{
	/*non recursive inorder traversal*/
	struct tnode *q;
	struct stack *s;
	int a=0;
	init(s);
	q=p;

	do
	{
		while(q!=NULL)
		{
			push(s,q);
			q=q->left;
		}
		if(!isempty(s))
		{
			q=pop(s);
			a++;
			q=q->right;
		}
	}while(!isempty(s) || q!=NULL);
	return a;
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
