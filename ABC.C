#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct tnode
{
	int val;
	struct tnode *left;
	struct tnode *right;
};

struct tnode * addnode(struct tnode *,int);
void print_tnode(struct tnode *);
struct tnode *deletenode(struct tnode *p,struct tnode *q,int num);

void main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	char ch='y';
	q=NULL;
	clrscr();
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
	printf("Enter the value to be deleted : ");
	scanf("%d",&num);
	p=deletenode(p,q,num);
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
	if(p==NULL)
		return;
	else
	{
		print_tnode(p->left);
		printf(" %d",p->val);
		print_tnode(p->right);
	}
}
struct tnode *deletenode(struct tnode *p,struct tnode *q,int num)
{
	if(p!=NULL)
	{
		if(p->val!=num)
		{
			q=addnode(q,p->val);
			q->left=deletenode(p->left,q->left,num);
			q->right=deletenode(p->right,q->right,num);
		}
	}
	return q;
}/*Non recursive inorder traversal of binary tree*/
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


void main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	char ch='y';
	q=NULL;
	clrscr();
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
			printf(" %d",q->val);
			q=q->right;
		}
	}while(!isempty(s) || q!=NULL);
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


void main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	int a,b,c,d;
	int e,f;
	char ch='y';

	q=NULL;
	clrscr();
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


void main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	int a,b;
	char ch='y';
	q=NULL;
	clrscr();
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
/*Implement the tree using array*/
/*Please create the inorder traversal for this tree*/

#include <stdio.h>
#include <conio.h>
#include "stack.h"

#define MAXNODES 100

#define TRUE 1
#define FALSE 0

struct tree
{
	int info;
	int used;
}nodes[MAXNODES];

void maketree(int);
void setleft(int,int);
void setright(int,int);
void inorder_traversal();

void main()
{
	int p,q,num;
	char ch='y';
	clrscr();
	printf("Enter the root node : ");
	scanf("%d",&num);
	maketree(num);

	while(ch=='y' || ch=='Y')
	{
		printf("Enter the number to be added : ");
		scanf("%d",&num);
		fflush(stdin);
		p=q=0;
		while(q<MAXNODES && nodes[q].used==TRUE && num!=nodes[p].info)
		{
			p=q;
			if(num<nodes[p].info)
				q= 2 * p + 1;
			else
				q= 2 * p + 2;
		}
		if(num==nodes[p].info)
			printf("\nDuplicate number");
		else if(num<nodes[p].info)
			setleft(p,num);
		else
			setright(p,num);

		printf("Do you want to add more elements to tree y/n : ");
		ch=getchar();
		fflush(stdin);
	}
	inorder_traversal();
	getch();
}
void maketree(int x)
{
	int p;
	nodes[0].info=x;
	nodes[0].used=TRUE;

	for(p=1;p<MAXNODES;p++)
		nodes[p].used=FALSE;
}
void setleft(int p,int x)
{
	int q;
	q= 2 * p + 1;
	if(q>=MAXNODES)
		printf("\nOverflow");
	else if(nodes[q].used==TRUE)
		printf("\Invalid insertion");
	else
	{
		nodes[q].info=x;
		nodes[q].used=TRUE;
	}
}
void setright(int p,int x)
{
	int q;
	q= 2 * p + 2;
	if(q>=MAXNODES)
		printf("\nOverflow");
	else if(nodes[q].used==TRUE)
		printf("\Invalid insertion");
	else
	{
		nodes[q].info=x;
		nodes[q].used=TRUE;
	}
}
void inorder_traversal()
{
	int p=0;
	stack *s;
	init(s);
	do
	{
		while(nodes[p].used==TRUE)
		{
			push(s,p);
			p=2*p+1;
		}
		if(!isempty(s))
		{
			p=pop(s);
			printf(" %d",nodes[p].info);
			p=2*p+2;
		}
	}while(nodes[p].used==TRUE || !isempty(s));
}/*Program to delete element from binary tree
Find an element in tree
Deletes min element from tree
After deleting the element it will rearange the tree*/

#include <stdio.h>
#include <conio.h>
struct tnode
{
	int info;
	struct tnode *left;
	struct tnode *right;
};

struct tnode * addnode(struct tnode *p,int num);
void in_traversal(struct tnode *p);
struct tnode * deletemin(struct tnode *p,int *a);
struct tnode *del_element(struct tnode *p,int x);
int member(struct tnode *p,int x);

void main()
{
	struct tnode *p;
	int num;
	char ch='y';
	clrscr();
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
	in_traversal(p);
	printf("\nEnter the number to be found in tree : ");
	scanf("%d",&num);
	num=member(p,num);
	if(num==1)
		printf("Found");
	else
		printf("Not found");

	getch();
}
struct tnode * addnode(struct tnode *p,int num)
{
	if(p==NULL)
	{
		p=(struct tnode *)malloc(sizeof(struct tnode));
		p->info=num;
		p->left=NULL;
		p->right=NULL;
	}
	else if(num<p->info)
		p->left=addnode(p->left,num);
	else
		p->right=addnode(p->right,num);
	return p;
}
void in_traversal(struct tnode *p)
{
	if(p==NULL)
		return;
	else
	{
		in_traversal(p->left);
		printf(" %d",p->info);
		in_traversal(p->right);
	}
}
/*here a is used hold the value of deleted node*/
struct tnode * deletemin(struct tnode *p,int *a)
{
	if(p->left==NULL)
	{
		*a=p->info;
		p=p->right;
	}
	else
		p->left=deletemin(p->left,a);
	return p;
}
/*Delete the given element x */
struct tnode *del_element(struct tnode *p,int x)
{
	if(p!=NULL)
	{
		if(x<p->info)
			p->left=del_element(p->left,x);
		else if(x>p->info)
			p->right=del_element(p->right,x);
		else if(p->left==NULL && p->right==NULL)
			p=NULL;
		else if(p->left==NULL)
			p=p->right;
		else if(p->right==NULL)
			p=p->left;
		else
		{
			/*Both children are available */
			/*rearangement of tree*/
			struct tnode *q;
			int a;
			q=p->left;
			p->right=deletemin(p->right,&a);
			p->info=a;
			p->left=q;
		}
	}
	return p;
}
/*Find the element x in tree and returns 1 if found, 0 otherwise*/
int member(struct tnode *p,int x)
{
	if(p==NULL)
		return 0;
	else if(x==p->info)
		return 1;
	else if(x<p->info)
		return member(p->left,x);
	else
		return member(p->right,x);
}/*Non recursive preorder traversal of binary tree*/
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


void main()
{
	struct tnode *p;
	struct tnode *q;
	int num;
	char ch='y';
	q=NULL;
	clrscr();
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
			printf(" %d",q->val);
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
