#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
	int top;
	int val[MAX];
}stack;

void init(stack *);
void push(stack *,int);
int isfull(stack *);
int pop(stack *);
int isempty(stack *);

void input_exp(char []);
void convert_in_to_post(char [],char []);
int isoperator(char);
int evaluate(char []);
int perform(int a,int b,char ch);
int precedence(char ch);

int main()
{
	char infix[100],postfix[100];
	int result;
	input_exp(infix);
	convert_in_to_post(infix,postfix);
	printf("The post expresion is %s",postfix);
	result=evaluate(postfix);
	printf("\nThe result is %d",result);
	getch();
	return 0;
}

void init(stack *p)
{
	p->top=-1;
}
void push(stack *p,int num)
{
	if(isfull(p))
		printf("Overflow");
	else
		p->val[++p->top]=num;
}
int isfull(stack *p)
{
	return (p->top>=MAX-1)?1:0;
}
int pop(stack *p)
{
	if(isempty(p))
	{
		printf("Underflow");
		exit(1);
	}
	else
		return p->val[p->top--];
}
int isempty(stack *p)
{
	return (p->top<0)?1:0;
}

void input_exp(char s[])
{
	char ch;
	int i;
	printf("Enter the valid infix expression by enclosing it into paranthesis (): ");
	for(i=0;(ch=getchar())!='\n';i++)
		s[i]=ch;
	s[i]='\0';

}
void convert_in_to_post(char in[],char post[])
{
	stack *opst;
	char ch,op;
	int i,j;
	init(opst);
	for(i=0,j=0; in[i]!='\0'; i++)
	{
		ch=in[i];
		if(isoperator(ch))
		{
			while(precedence(op=pop(opst))>=precedence(ch))
				post[j++]=op;

			push(opst,op);
			push(opst,ch);
		}
		else if(ch=='(')
			push(opst,ch);
		else if(ch==')')
		{
			while((op=pop(opst))!='(')
				post[j++]=op;
		}
		else
			post[j++]=ch;
	}
	post[j]='\0';
}
int precedence(char ch)
{
	switch(ch)
	{
		case '$': return 9;
		case '*': return 8;
		case '/': return 8;
		case '%': return 8;
		case '+': return 7;
		case '-': return 7;
		default : return 1;
	}
}
int isoperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$')
		return 1;
	else
		return 0;
}
int evaluate(char s[])
{
	int op1,op2,result;
	int i;
	char ch;
	stack *opst;
	init(opst);
	for(i=0;s[i];i++)
	{
		ch=s[i];
		if(isoperator(ch))
		{
			op2=pop(opst);
			op1=pop(opst);
			result=perform(op1,op2,ch);
			push(opst,result);
		}
		else
			push(opst,ch-'0');
	}
	return pop(opst);
}
int perform(int a,int b,char ch)
{
	switch(ch)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		case '$':return pow(a,b);
	}
}
