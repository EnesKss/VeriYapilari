#include <stdio.h>

int sum(int n) {
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}

int main() {
    int sayi;
    printf("Toplamýný hesaplamak istediðiniz sayýyý girin: ");
    scanf("%d", &sayi);

    if (sayi < 1) {
        printf("Lütfen 1 veya daha büyük bir sayý girin.\n");
    } else {
        int sonuc = sum(sayi);
        printf("1'den %d'e kadar olan sayýlarýn toplamý: %d\n", sayi, sonuc);
    }

    return 0;
}
