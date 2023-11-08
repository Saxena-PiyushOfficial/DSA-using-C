#include<stdio.h>
#include<stdlib.h>
struct list
{
    int coff;
    int pow;
    struct list *next;
};
struct list *addnode(struct list*,int,int);
void print_poly(struct list*);
struct list *addition(struct list*,struct list*,struct list*);
struct list *subtract(struct list*,struct list*,struct list*);
struct list *multiply(struct list*,struct list*,struct list*);
struct list *copy(struct list*,struct list*);
void main()
{
     struct list *first,*second,*add,*pro,*sub;
     int c,m;
     first=NULL;
     second=NULL;
     add=NULL;
     pro=NULL;
     sub=NULL;
     printf("Enter the first polynomial:\n");
     for(;;)
     {
         printf("Enter the cofficient:\n");
         scanf("%d",&c);
         printf("Enter the power:\n");
         scanf("%d",&m);
         if(m==-1)
            break;
         first=addnode(first,c,m);
     }
     printf("Enter the second polynomial:\n");
        for(;;)
       {
         printf("Enter the cofficient:\n");
         scanf("%d",&c);
         printf("Enter the power:\n");
         scanf("%d",&m);
         if(m==-1)
            break;
         second=addnode(second,c,m);
       }
       printf("\n");
       print_poly(first);
       printf("\n");
        print_poly(second);
       printf("\n");
       add=addition(first,second,add);
       printf("Addition:\n");
       print_poly(add);
       printf("\n");
       sub=subtract(first,second,sub);
        printf("Subtraction:\n");
       print_poly(sub);
       printf("\n");
       pro=multiply(first,second,pro);
        printf("Product:\n");
       print_poly(pro);
}
struct list *addnode(struct list*p,int c,int m)
{
    if(p==NULL)
    {
        p=(struct list*)malloc(sizeof(struct list));
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
        struct list *q;
        q=(struct list*)malloc(sizeof(struct list));
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
void print_poly(struct list*p)
{
   if(p==NULL)
    return;
   else
   {
          if(p->coff>0 && p->pow>=2)
			printf(" +%dx^%d",p->coff,p->pow);
		else if(p->coff<0 && p->pow>=2)
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
struct list *multiply(struct list *p,struct list *q,struct list *pro)
{
	if(p!=NULL)
	{
		struct list *r;
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
struct list *addition(struct list *p,struct list *q,struct list *sum)
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
          sum=(struct list*)malloc(sizeof(struct list));
          sum->coff=p->coff;
          sum->pow=p->pow;
          sum->next=NULL;
          sum->next=addition(p->next,q,sum->next);
      }
       else if(p->pow<q->pow)
      {
          sum=(struct list*)malloc(sizeof(struct list));
          sum->coff=q->coff;
          sum->pow=q->pow;
          sum->next=NULL;
          sum->next=addition(p,q->next,sum->next);
      }
      else
      {
          sum=(struct list*)malloc(sizeof(struct list));
          sum->coff=p->coff+q->coff;
          sum->pow=p->pow;
          sum->next=NULL;
          sum->next=addition(p->next,q->next,sum->next);
      }
  }
  return sum;
}
struct list *subtract(struct list *p,struct list *q,struct list *diff)
{
   if(p==NULL && q==NULL)
        diff=NULL;
  else if(p==NULL)
    diff=copy(q,diff);
  else if(q==NULL)
  diff=copy(p,diff);
  else
  {
      if(p->pow>q->pow)
      {
          diff=(struct list*)malloc(sizeof(struct list));
          diff->coff=p->coff;
          diff->pow=p->pow;
          diff->next=NULL;
          diff->next=subtract(p->next,q,diff->next);
      }
       else if(p->pow<q->pow)
      {
          diff=(struct list*)malloc(sizeof(struct list));
          diff->coff=q->coff*(-1);
          diff->pow=q->pow;
          diff->next=NULL;
          diff->next=subtract(p,q->next,diff->next);
      }
      else
      {
          diff=(struct list*)malloc(sizeof(struct list));
          diff->coff=p->coff-q->coff;
          diff->pow=p->pow;
          diff->next=NULL;
          diff->next=subtract(p->next,q->next,diff->next);
      }
  }
  return diff;
}
struct list *copy(struct list *p,struct list *q)
{
    if(p!=NULL)
	{
		q=(struct poly *)malloc(sizeof(struct list));
		q->coff=p->coff;
		q->pow=p->pow;
		q->next=NULL;
		q->next=copy(p->next,q->next);
	}
	return q;
}
