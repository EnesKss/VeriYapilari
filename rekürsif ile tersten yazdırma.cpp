#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node*next;
	int data;
};

void olustur(struct node**head,int data)
{
	if(*head==NULL)
	{
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->data=data;
		(*head)->next=NULL;
	}
	else{
		struct node*yeni=(struct node*)malloc(sizeof(struct node));
		struct node*temp;
		yeni->next=NULL;
		yeni->data=data;
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=yeni;
	}
}
void rekursif(struct node* temp)
{
    if (temp == NULL)
    {
        return;
    }
    else
    {
        rekursif(temp->next);
        printf("%d ", temp->data);
    }
}


int main()
{
	int adet,deger;
	printf("liste kac elemanli olacak : ");
	struct node*head=NULL;
	scanf("%d",&adet);
	int i;
	for(i=0;i<adet;i++)
	{
		printf("deger giriniz : ");
		scanf("%d",&deger);
		olustur(&head,deger);
	}
	
	rekursif(head);
	
	
	return 0;
}
