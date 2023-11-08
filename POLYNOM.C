/*Addition, subtraction and multiplication of two polynomials up to n degree */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct poly
{
	int coff,pow;
	struct poly *next;
};

struct poly * addnode(struct poly *,int,int);
void print_poly(struct poly *);
struct poly * multiply(struct poly *,struct poly *,struct poly *);
struct poly * addition(struct poly *,struct poly *,struct poly *);
struct poly * subtract(struct poly *,struct poly *,struct poly *);
struct poly * copy(struct poly *,struct poly *);

int main()
{
	struct poly *p1,*p2,*pro;
	int c,m;
	p1=NULL;
	p2=NULL;
	pro=NULL;
	printf("\nEnter the first polynomial : \n");
	for(;;)
	{
		printf("Enter the cofficient : ");
		scanf("%d",&c);
		printf("Enter the power : ");
		scanf("%d",&m);
		if(m==-1)
			break;
		p1=addnode(p1,c,m);
	}
	printf("\nEnter the second polynomial : \n");
	for(;;)
	{
		printf("Enter the cofficient : ");
		scanf("%d",&c);
		printf("Enter the power : ");
		scanf("%d",&m);
		if(m==-1)
			break;
		p2=addnode(p2,c,m);
	}
	printf("\n");
	print_poly(p1);
	printf("\n");
	print_poly(p2);
	pro=addition(p1,p2,pro);
	printf("\n");
	print_poly(pro);
	pro=NULL;
	pro=multiply(p1,p2,pro);
	printf("\n");
	print_poly(pro);
	getch();
	return 0;
}
struct poly *addnode(struct poly *p,int c,int m)
{
	if(p==NULL)
	{
		p=(struct poly *)malloc(sizeof(struct poly));
		p->coff=c;
		p->pow=m;
		p->next=NULL;
	}
	else if(p->pow==m)
	{
		p->coff=p->coff+c;
	}
	else if(p->pow<m)
	{
		struct poly *q;
		q=(struct poly *)malloc(sizeof(struct poly));
		q->coff=c;
		q->pow=m;
		q->next=NULL;
		q->next=p;
		p=q;
	}
	else
		p->next=addnode(p->next,c,m);
	return p;
}
void print_poly(struct poly *p)
{
	if(p==NULL)
		return;
	else
	{
		if(p->coff>0 && p->pow>=2)
			printf(" +%dx^%d",p->coff,p->pow);
		else if(p->coff<0 && p->pow>1)
			printf(" %dx^%d",p->coff,p->pow);
		else if(p->coff<0 && p->pow==1)
			printf(" %dx",p->coff);
		else if(p->coff<0 && p->pow==0)
			printf(" %d",p->coff);
		else if(p->pow==1)
			printf(" +%dx",p->coff);
		else if(p->pow==0)
			printf(" +%d",p->coff);
		else
			printf(" %dx^%d",p->coff,p->pow);
		print_poly(p->next);
	}
}
struct poly *multiply(struct poly *p,struct poly *q,struct poly *pro)
{
	if(p!=NULL)
	{
		struct poly *r;
		r=q;
		while(r!=NULL)
		{
			pro=addnode(pro,p->coff*r->coff,p->pow+r->pow);
			r=r->next;
		}
		pro=multiply(p->next,q,pro);
	}
	return pro;
}
struct poly * addition(struct poly *p,struct poly *q,struct poly *sum)
{
	if(p==NULL && q==NULL)
		sum=NULL;
	else if(p==NULL)
		sum=copy(q,sum);
	else if(q==NULL)
		sum=copy(p,sum);
	else
	{
		if(p->pow>q->pow)
		{
			sum=(struct poly *)malloc(sizeof(struct poly));
			sum->coff=p->coff;
			sum->pow=p->pow;
			sum->next=NULL;
			sum->next=addition(p->next,q,sum->next);
		}
		else if(p->pow<q->pow)
		{
			sum=(struct poly *)malloc(sizeof(struct poly));
			sum->coff=q->coff;
			sum->pow=q->pow;
			sum->next=NULL;
			sum->next=addition(p,q->next,sum->next);
		}
		else
		{
			sum=(struct poly *)malloc(sizeof(struct poly));
			sum->coff=p->coff+q->coff;
			sum->pow=p->pow;
			sum->next=NULL;
			sum->next=addition(p->next,q->next,sum->next);
		}
	}
	return sum;
}
struct poly * subtract(struct poly *p,struct poly *q,struct poly *dif)
{
	if(p==NULL && q==NULL)
		dif=NULL;
	else if(p==NULL)
		dif=copy(q,dif);
	else if(q==NULL)
		dif=copy(p,dif);
	else
	{
		if(p->pow>q->pow)
		{
			dif=(struct poly *)malloc(sizeof(struct poly));
			dif->coff=p->coff;
			dif->pow=p->pow;
			dif->next=NULL;
			dif->next=subtract(p->next,q,dif->next);
		}
		else if(p->pow<q->pow)
		{
			dif=(struct poly *)malloc(sizeof(struct poly));
			dif->coff=q->coff*(-1);
			dif->pow=q->pow;
			dif->next=NULL;
			dif->next=subtract(p,q->next,dif->next);
		}
		else
		{
			dif=(struct poly *)malloc(sizeof(struct poly));
			dif->coff=p->coff-q->coff;
			dif->pow=p->pow;
			dif->next=NULL;
			dif->next=subtract(p->next,q->next,dif->next);
		}
	}
	return dif;
}
struct poly * copy(struct poly *p,struct poly *q)
{
	if(p!=NULL)
	{
		q=(struct poly *)malloc(sizeof(struct poly));
		q->coff=p->coff;
		q->pow=p->pow;
		q->next=NULL;
		q->next=copy(p->next,q->next);
	}
	return q;
}
