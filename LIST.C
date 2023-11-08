#include <stdio.h>
#include <stdlib.h>
struct list
{
	int val;
	struct list *next;
};

struct list * addnode(struct list *,int);
void print_list(struct list *);
struct list * insertnode(struct list *p,int val);
struct list * deletenode(struct list *,int);
int find(struct list *p,int n);
struct list * remove_duplicate(struct list *p,struct list *q);
struct list * reverse(struct list *p,struct list *q);

int main()
{
	struct list *first,*second;
	int num;
	char ch='y';
	first=NULL;
	second=NULL;
	while(ch=='y' || ch=='Y')
	{
		printf("Enter the number to be added :");
		scanf("%d",&num);
		fflush(stdin);
		first=addnode(first,num);
		printf("Do you want to add more elements to list y/n : ");
		ch=getchar();
		fflush(stdin);
	}
	printf("\nfirst");
	print_list(first);
	printf("->NULL");

	second=reverse(first,second);
	printf("\nsecond");
	print_list(second);
	printf("->NULL");
}
struct list *addnode(struct list *p,int val)
{
	if(p==NULL)
	{
		p=(struct list *)malloc(sizeof(struct list));
		p->val=val;
		p->next=NULL;
	}
	else if(p->val>val)
		p=insertnode(p,val);
	else
		p->next=addnode(p->next,val);
	return p;
}
void print_list(struct list *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		printf("->%d",p->val);
		print_list(p->next);
	}
}
struct list * insertnode(struct list *p,int val)
{
	if(p==NULL)
	{
		p=(struct list *)malloc(sizeof(struct list));
		p->val=val;
		p->next=NULL;
	}
	else if(val<p->val)
	{
		struct list *q;
		q=(struct list *)malloc(sizeof(struct list));
		q->val=val;
		q->next=NULL;
		q->next=p;
		p=q;
	}
	else
		p->next=addnode(p->next,val);
	return p;
}
struct list *deletenode(struct list *p,int val)
{
	if(p!=NULL)
	{
		if(p->val==val)
		{
			struct list *q;
			q=p;
			p=p->next;
			free(q);
		}
		else
			p->next=deletenode(p->next,val);
	}
	return p;
}
struct list *copylist(struct list *p,struct list *q)
{
	if(p!=NULL)
	{
		q=(struct list *)malloc(sizeof(struct list));
		q->val=p->val;
		q->next=NULL;
		q->next=copylist(p->next,q->next);
	}
	return p;
}
struct list *concatelist(struct list *p,struct list *q)
{
	if(p!=NULL)
		p->next=concatelist(p->next,q);
	else if(q!=NULL)
		p=copylist(q,p);
	return p;
}
int find(struct list *p,int n)
{
	int a;
	if(p==NULL)
		return 0;
	else if(p->val==n)
		return 1;
	else
	   a=find(p->next,n);
}
struct list * remove_duplicate(struct list *p,struct list *q)
{
	if(p!=NULL)
	{
		if(!find(q,p->val))
		{
			q=addnode(q,p->val);
		}
		q=remove_duplicate(p->next,q);
	}
	return q;
}
struct list * reverse(struct list *p,struct list *q)
{
	if(p!=NULL)
	{
		struct list *r;
		r=(struct list *)malloc(sizeof(struct list));
		r->val=p->val;
		r->next=NULL;
		r->next=q;
		q=r;
		q=reverse(p->next,q);
	}
	return q;
}
