#include<stdio.h>
#include<stdlib.h>
// tek yönlü doðrusal baðlý liste uygulamasý 

struct ogrenci{
	int no;
	char ad[40];
	int vize,final;
	double ort;
	struct ogrenci *next;
};

typedef struct ogrenci node;

node * ekle(node *head)
{
	node *ogr=(node *)malloc(sizeof(node));
	printf("Ogrenci no: "); scanf("%d",&ogr->no);
	printf("Adi: "); scanf("%s",&ogr->ad);
	printf("vize: "); scanf("%d",&ogr->vize);
	printf("final: "); scanf("%d",&ogr->final);
	ogr->ort=ogr->vize*0.4 + ogr->final*0.6;
	
	if(head==NULL)
		{
			head=ogr;
			head->next=NULL;
			printf("Liste olusturuldu , ilk ogrenci kayit edildi  \n");
		}
	else
		{
			ogr->next=head;
			head=ogr;
			printf("Ogrenci kayit edildi \n");

		}
			
	return head;	
}

node *sil(node *head)
{
	
	if(head==NULL)
		{
			printf("liste bos , silinecek ogrenci yok \n");
		}
	else
		{
			int ogrno;
			printf("ogrenci no: "); scanf("%d",&ogrno);
			if(head->no==ogrno && head->next==NULL)
				{
					free(head);
					head=NULL;
					printf("listede kalan son ogrenci silindi \n");
				}
				
			else if(head->no==ogrno && head->next!=NULL)
				{
					node *p=head->next;
					free(head);
					head=p;
					printf("%d numaralý ogrenci silindi. \n",ogrno);
				}
			else
				{	
				node *p=head;
				node *q=head;
				while(p->next!=NULL)
					{
						if(p->no==ogrno)
						{
							q->next=p->next;
							free(p);
							printf("%d numaralý ogrenci silindi. \n",ogrno);
							break;

						}
					q=p;	
					p=p->next;
						
					}
					if(p->no==ogrno)
						{
							q->next=NULL;
							free(p);
							printf("%d numaralý ogrenci silindi. \n",ogrno);
						}	
				}	
		}	
	
	return head;
}
node *yazdir(node *head)
{
	system("cls");
	if(head==NULL)
		{
			printf("Liste bos \n");
		}
	else
		{
		node *p=head;
		while(p!=NULL)
			{
			printf("*************************** \n");
			printf("No : %d   Ad: %s  Vize: %d   Final: %d  Ortalam: %.2f  \n",p->no,p->ad,p->vize,p->final,p->ort)	;
			p=p->next;
			}	
			
		}	
	
	return head;
}
node *enYuksekPuan(node *head)
{
	system("cls");
	int buyukort=head->ort;
	node *buyukdugum=head;
	if(head==NULL)
		{
			printf("liste bos !!!! \n");
		}
	else
		{
			node *p=head;
			while(p!=NULL)
				{
					if(buyukort<p->ort)
						{
							buyukort=p->ort;
							buyukdugum=p;
						}
						p=p->next;
				}
				printf("En yuksek ortalamasi olan ogrenci bilgileri \n");
				printf("no: %d \n",buyukdugum->no   );
				printf("ad: %s \n",buyukdugum->ad  );
				printf("vize: %d \n",buyukdugum->vize   );
				printf("final: %d \n",buyukdugum->final   );
				printf("ortalama: %.2f \n",buyukdugum->ort   );
			
		}	
	
	return head;
}


int main()
{
	int secim;
	node *head=NULL;
	while(1)
		{
			printf("\ntek yonlu dogrusal bagli liste ile ogrenci kayit uygulamasý \n");
			printf("1---ekle \n");
			printf("2---sil \n");	
			printf("3---yazdir \n");	
			printf("4---en yuksek ortalamasi olan ogrenciyi goster \n");	
			printf("0---cikis \n");
			printf("seciminizi yapin [0-4] \n");
			scanf("%d",&secim);
			switch(secim)
			{
				case 1: head=ekle(head);
				break;
				
				case 2: head=sil(head);
				break;
				
				case 3: head=yazdir(head);
				break;
				 
				case 4: head=enYuksekPuan(head);
				break;
				
				case 0: exit(0);
				default : printf("hatali secim !!!");
			
			
			}
				
		
		}
}







































