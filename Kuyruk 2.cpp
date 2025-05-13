#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *temp = NULL;
struct node *front = NULL; //BAS DÜÐÜM
struct node *rear = NULL; //SON DÜÐÜM

void elemanEkle(int veri) {
    struct node *eleman = (struct node *)malloc(sizeof(struct node));
    eleman->data = veri;

    if (front == NULL) {
        front = eleman;
        front->next = front;
        rear = eleman;
        rear->next = NULL;
    } else if (front->next == front) {
        rear->next = eleman;
        rear = eleman;
        rear->next = NULL;
        front->next = rear;
    } else {
        rear->next = eleman;
        rear = eleman;
        rear->next = NULL;
    }
}

void elemanCikar() {
    if (front == NULL) {
        printf("kuyruk bostur. \n");
    } else {
        temp = front->next;
        free(front);
        front = temp;
    }
}

void yazdir() {
    if (front == NULL) {
        printf("kuyruk bos \n");
    } else {
        temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("\n");
    }
}

int main() {
    int secim, sayi;
    while (1) {
        printf(" KUYRUK \n");
        printf("1--- Ekle \n");
        printf("2--- Cikar \n");
        printf("3--- Yazdir \n");
        printf("4--- Cikis \n");
        scanf("%d", &secim);

        switch (secim) {
            case 1: 
                printf("sayi girin: ");
                scanf("%d", &sayi);
                elemanEkle(sayi);
                break;

            case 2: 
                elemanCikar();
                break;

            case 3:
                yazdir();
                break;

            case 4:
                return 0;
        }
    }

    return 0;
}

