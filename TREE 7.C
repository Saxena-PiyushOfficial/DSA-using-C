/*Implement the tree using array*/
/*Please create the inorder traversal for this tree*/

#include <stdio.h>
#include <conio.h>

#define MAXNODES 100

#define TRUE 1
#define FALSE 0
typedef struct
{
	int top;
	int val[MAXNODES];
}stack;

struct tree
{
	int info;
	int used;
}nodes[MAXNODES];



void init(stack *p)
{
	p->top=-1;
}


void push(stack *p,int num)
{
	if(p->top>=MAXNODES)
	{
		printf("overflow stack");
		
	}
	p->val[++p->top]=num;
}


int pop(stack *p)
{
	if(p->top<0)
	{
		printf("\nUnderflow");
		
	}
	return p->val[p->top--];
}



int isempty(stack *p)
{
	if(p->top<0)
		return 1;
	else
		return 0;
}


void maketree(int);
void setleft(int,int);
void setright(int,int);
void inorder_traversal();

int main()
{
	int p,q,num;
	char ch='y';
	
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
}
