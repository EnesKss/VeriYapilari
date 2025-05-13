#include <stdio.h>

int ebob(int m, int n) {
    if (n == 0)
        return m;
    else
        return ebob(n, m % n);
}

int main() {
    int sayi1, sayi2;
    printf("�ki say�n�n en b�y�k ortak b�lenini (EBOB) hesaplamak i�in iki say� girin:\n");
    scanf("%d %d", &sayi1, &sayi2);

    if (sayi1 < 0 || sayi2 < 0) {
        printf("Negatif say�lar i�in EBOB hesaplanamaz.\n");
    } else {
        int sonuc = ebob(sayi1, sayi2);
        printf("EBOB(%d, %d) = %d\n", sayi1, sayi2, sonuc);
    }

    return 0;
}
