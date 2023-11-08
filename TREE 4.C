/*Program to count total no of leaf nodes*/
/*and count non-leaf nodes besides root node*/
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
int count_leaves(struct tnode *);
int count_non_leaf(struct tnode *);


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
	int a,b;
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
	a=count_leaves(p);
	printf("\n Total leaves are %d",a);
	b=count_non_leaf(p);
	printf("\n Total non leaf nodes are %d",b);
	
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


int count_leaves(struct tnode *p)
{
	struct tnode *q;
	struct stack *s;
	int count=0;
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
			if(q->left==NULL && q->right==NULL)
				count++;
			q=q->right;
		}
	}while(!isempty(s) || q!=NULL);

	return count;
}



int count_non_leaf(struct tnode *p)
{
	struct tnode *q;
	struct stack *s;
	int count=0;
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
			if(q->left!=NULL || q->right!=NULL)
				count++;
			q=q->right;
		}
	}while(!isempty(s) || q!=NULL);

	return count-1;/*subtract the root node*/
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
