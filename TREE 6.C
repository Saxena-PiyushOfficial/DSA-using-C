/*Program to delete element from binary tree
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
}