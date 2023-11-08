#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4

struct list
{
	int row;
	int col;
	int element;
	struct list *next;
};

struct list * addnode(struct list *,int,int,int);
void print_list(struct list *);
struct list * addmatrix(struct list *p,struct list *q,struct list *sum);
struct list * copy(struct list *p,struct list *q);
struct list * multiply(struct list *p,struct list *q,struct list *pro);

int main()
{
	int mat[M][N],mat1[M][N];
	int i,j;
	struct list *first,*second,*sum,*pro;
	first=NULL;
	second=NULL;
	sum=NULL;
	pro=NULL;
	printf("Enter the first matrix...............................\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("Enter the element of sparce matrix ");
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<M;i++)							//sparce matrix conversion of 1st matrix
	{
		for(j=0;j<N;j++)
		{
			if(mat[i][j]!=0)
			{
				first=addnode(first,i,j,mat[i][j]);
			}
		}
	}
	printf("Enter the second matrix...............................\n");
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("Enter the element of sparce matrix ");
			scanf("%d",&mat1[i][j]);
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(mat1[i][j]!=0)
			{
				second=addnode(second,i,j,mat1[i][j]);
			}
		}
	}
     printf("\n");
	print_list(first);
	  printf("\n");
	print_list(second);
	sum=addmatrix(first,second,sum);
	 printf("\n");
	print_list(sum);
	pro=multiply(first,second,pro);
	  printf("\n");
	print_list(pro);
}
struct list * addnode(struct list *p,int row,int col,int x)
{
	if(p==NULL)
	{
		p=(struct list *)malloc(sizeof(struct list));
		p->row=row;
		p->col=col;
		p->element=x;
		p->next=NULL;
	}
	else
		p->next=addnode(p->next,row,col,x);
	return p;
}
void print_list(struct list *p)
{
	if(p!=NULL)
	{
	    printf("\n%d %d",p->row,p->col);
		  printf(" %d",p->element);

		print_list(p->next);
	}
}
struct list * addmatrix(struct list *p,struct list *q,struct list *sum)
{
	if(p==NULL && q==NULL)
		sum=NULL;
	else if(p==NULL)
		sum=copy(q,sum);
	else if(q==NULL)
		sum=copy(p,sum);
	else
	{
		if(p->row<q->row)
		{
			sum=(struct list *)malloc(sizeof(struct list));
			sum->row=p->row;
			sum->col=p->col;
			sum->element=p->element;
			sum->next=NULL;
			sum->next=addmatrix(p->next,q,sum->next);
		}
		else if(p->row>q->row)
		{
			sum=(struct list *)malloc(sizeof(struct list));
			sum->row=q->row;
			sum->col=q->col;
			sum->element=q->element;
			sum->next=NULL;
			sum->next=addmatrix(p,q->next,sum->next);
		}
		else
		{
			if(p->col<q->col)
			{
				sum=(struct list *)malloc(sizeof(struct list));
				sum->row=p->row;
				sum->col=p->col;
				sum->element=p->element;
				sum->next=NULL;
				sum->next=addmatrix(p->next,q,sum->next);
			}
			else if(p->col>q->col)
			{
				sum=(struct list *)malloc(sizeof(struct list));
				sum->row=q->row;
				sum->col=q->col;
				sum->element=q->element;
				sum->next=NULL;
				sum->next=addmatrix(p,q->next,sum->next);
			}
			else
			{
				sum=(struct list *)malloc(sizeof(struct list));
				sum->row=p->row;
				sum->col=p->col;
				sum->element=p->element+q->element;
				sum->next=NULL;
				sum->next=addmatrix(p->next,q->next,sum->next);
			}
		}
	}
	return sum;
}
struct list * copy(struct list *p,struct list *q)
{
	if(p!=NULL)
	{
		q=(struct list *)malloc(sizeof(struct list));
		q->row=p->row;
		q->col=p->col;
		q->element=p->element;
		q->next=NULL;
		q->next=copy(p->next,q->next);
	}
	return q;
}
struct list * multiply(struct list *p,struct list *q,struct list *pro)
{
	struct list *r;
	int ans,t;
	if(p!=NULL)
	{
		r=q;
		ans=0;
		while(r!=NULL)
		{
			if(p->col==r->row)
			{
				ans=ans+p->element*r->element;
				t=r->col;
			}
			r=r->next;
		}
		if(ans!=0)
			pro=addnode(pro,p->row,t,ans);
		pro=multiply(p->next,q,pro);
	}
	return pro;
}
