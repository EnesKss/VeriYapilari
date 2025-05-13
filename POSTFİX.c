#include <stdio.h>
#include <stdlib.h>
#define size 100

typedef struct
{
	struct node*next;
	int data;
}node;

typedef struct
{
	node*top;
	int count;
}stack;

void ilklendirme(stack*stk)
{
	stk->top=NULL;
	stk->count=0;
}
void push(stack*stk,int data)
{
	if(stk->count==size)
	{
		printf("stack doludur");
	}
	else
	{
		node*temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->next=stk->top;
		stk->top=temp;
		stk->count++;
	}
}
int  pop(stack*stk)
{
	if(stk->count==0)
	{
		printf("kuyruk bostur");
	}
	else
	{
		int  x=stk->top->data;
		node*temp=stk->top;
		stk->top=stk->top->next;
		free(temp);
		stk->count--;
		return x;



	}
}



int main() {

	char dizi[100];
	printf("lutfen postfix ifade giriniz\n");
	gets(dizi);
	stack n;
	int i=0;
	ilklendirme(&n);

	while(dizi[i]!='\0')
	{
		if(dizi[i]!='+'||dizi[i]!='-'||dizi[i]!='*'||dizi[i]!='/') //isdigit
		{
			push(&n,dizi[i]);
		}
		else
		{
		int x= pop(&n);
		int y= pop(&n);

		char op=dizi[i];
		switch(op)
		{
			case '+':
				push(&n,x+y);
				break;
			case '-':
				push(&n,x-y);
				break;
			case '*':
				push(&n,x*y);
				break;
			case '/':
				push(&n,x/y);
				break;
		}


		}
		i++;




}
printf("%d",pop(&n));
}
