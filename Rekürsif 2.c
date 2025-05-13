#include <stdio.h>

int sum(int n) {
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}

int main() {
    int sayi;
    printf("Toplam�n� hesaplamak istedi�iniz say�y� girin: ");
    scanf("%d", &sayi);

    if (sayi < 1) {
        printf("L�tfen 1 veya daha b�y�k bir say� girin.\n");
    } else {
        int sonuc = sum(sayi);
        printf("1'den %d'e kadar olan say�lar�n toplam�: %d\n", sayi, sonuc);
    }

    return 0;
}
