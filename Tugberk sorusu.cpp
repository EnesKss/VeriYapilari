#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5

int dizi[BOYUT],top;
		
void push(int veri)
{
	if(top==BOYUT-1)
	{
		printf("stack dolu");
	}
	else
	{
		top=top+1;
		dizi[top]=veri;
	}
}
	void pop()
	{
		if(top==-1)
		{
			printf("stack zaten bos");
		}
		else
		{
			top-=1;
		}
	}

	
	int peek()
	{
		return dizi[top];
	}
	
	void yazdir()
	{
		int i;
		for(i=0;i<top+1;i++)
		{
			printf(" %d ",dizi[i]);
		}
		printf("==> TOP");
	}
	int main()
	{
		int secim;
		top=-1;
		while(1==1){
		
		printf("\n1- Push");
		printf("\n2- Pop");
		printf("\n3- Peek");
		printf("\nLutfen secim yapiniz...");
		scanf("%d",&secim);
	
		switch(secim)
		{
			case 1: 
				printf("\n bir sayi giriniz...");
				scanf("%d",&secim);
				push(secim);
				yazdir();
				break;
				
			case 2:
				pop();
				yazdir();
				break;
			case 3:
				printf("\n Top degeri => %d",peek());
				break;	
			
			
	}
		}
	}
