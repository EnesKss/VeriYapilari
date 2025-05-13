#include<stdio.h>
#include<stdlib.h>


/*
-------------------------LÝSTE YAPMA----------------------------------------

struct node{
	
	int data;
	struct node* next;
};


int main()  {
	
	struct node* head =NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("Bellek boþ \n");
		return 1;
	}
	head->data=1;
	head->next=NULL;
	
	
	head->next=(struct node*)malloc(sizeof(struct node));
	if(head->next==NULL)
	{
	
		printf("bellek hatasý\n");
		return 1;
	}
	head->next->data=3;
	head->next->next=NULL;
	
	printf("%d",head->next->data);
}

*/



/*
    int data;
    struct node* next;
};

struct node* addhead(struct node* head, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Bellek yok\n");
    }
    temp->data = key;
    temp->next = head;
    head = temp;
    return head;
}

void ekranayazdir(struct node* head) {
    struct node* gecici = head;
    while (gecici != NULL) {
        printf("%d-> ", gecici->data);
        gecici = gecici->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    int n, key;

    printf("Kaç adet sayý gireceksiniz: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Sayý %d: ", i + 1);
        scanf("%d", &key);
        head = addhead(head, key);
    }

    printf("Liste: ");
    ekranayazdir(head);

    return 0;
}

*/

struct node{
	int data;
	struct node* next;
};

struct node* addlast(struct node* head, int key){
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("bellek yok");
		exit(1);
	}
	temp->data=key;
	temp->next=NULL;
	
	
	 if(head==NULL){
	 	head = temp;
	 }
	 else
	 {
	 	struct node* temp2=head;
	 	while(temp2->next != NULL)
	 	{
	 		temp2=temp2->next;
		}
		
		temp2->next=temp;
	 }
	return head;
}


void ekranayaz(struct node* head)
{
	struct node* gecici=head;
	
	while ( gecici != NULL)
	{
		printf("%d -> ",gecici->data);
		gecici=gecici->next;
	}
	
	printf("NULL \n");
}

int main(){
	struct node* head=NULL;
	
	int n, key;
	
	printf("kaç sayý girilcek? ");
	scanf("%d",&n);
	
	
	for (int i =0;i<n;i++)
	{
		printf("sayi %d ", i+1);
		scanf("%d",&key);
		head=addlast(head,key);
	}
	
	printf("Liste: ");
	ekranayaz(head);
}


















