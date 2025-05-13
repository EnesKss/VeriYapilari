#include<stdio.h>
#include<stdlib.h>
#define BOY 5

int dizi[BOY];
int bas = -1, son = -1; // bas= front   son =rear

void elemanEkle(int veri) {
    if (son == BOY - 1)
        printf("kuyruk doludur \n");
    else {
        if (bas == -1)
            bas = 0;

        son++;
        dizi[son] = veri;
    }
}

void elemanCikar() {
    if (bas == -1 || bas > son) {
        printf("Kuyruk bostur \n");
        bas = -1;
        son = -1;
    } else {
        bas = bas + 1;
    }
}

void yazdir() {
    system("cls");
    if (bas == -1) {
        printf("kuyruk bos \n");
    } else {
        int i;
        for (i = bas; i <= son; i++) {
            printf("%d ", dizi[i]);
        }
    }
    printf("\n"); // Daha iyi biçimlendirme için yeni satýr ekle
}

int main() {
    int secim, sayi;
    while (1) {
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
        printf(bas);
    }
}

