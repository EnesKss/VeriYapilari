#include <stdio.h>
#include <stdlib.h>
#define BOY 10

struct yigin
{
    int dizi[BOY];
    int top;
};

struct yigin y1;

void push(int sayi)
{
    if (y1.top == BOY - 1)
        printf("Yiðin doludur\n");
    else
    {
        y1.top++;
        y1.dizi[y1.top] = sayi;
    }
}

void pop()
{
    if (y1.top == -1)
        printf("Cikacak eleman yoktur, Yýðýn boþtur\n");
    else
    {
        int cikanSayi = y1.dizi[y1.top];
        y1.top--;

        printf("%d yiðindan cikartilmiþtir\n", cikanSayi);
    }
}

void yazdir()
{
    system("cls");
    if (y1.top == -1)
        printf("Yigin bostur\n");
    else
    {
        int i;
        for (i = y1.top; i > -1; i--)
        {
            printf("%d\n", y1.dizi[i]);
        }
    }
}

int main()
{
    y1.top = -1;
    int secim, sayi;

    do
    {
        printf("\n YIGIN (STACK) \n");
        printf("1---> Eleman ekle (push) \n");
        printf("2---> Eleman cýkar (pop) \n");
        printf("3---> Yazdýr (display) \n");
        printf("4---> Çikis (exit) \n");
        printf("Seciminizi yapiniz: \n");
        scanf("%d", &secim);

        switch (secim)
        {

        case 1:
            printf("Eklenecek sayi: ");
            scanf("%d", &sayi);
            push(sayi);
            break;

        case 2:
            pop();
            break;

        case 3:
            yazdir();
            break;

        case 4:
            printf("Programdan çýkýlýyor... \n");
            break;

        default:
            printf("Geçersiz secim! Tekrar deneyin.\n");
        }

    } while (secim != 4);

    return 0;
}
