#include <stdio.h>

int fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    int sayi;
    printf("Faktoriyeli hesaplanacak sayiyi girin: ");
    scanf("%d", &sayi);

    if (sayi < 0) {
        printf("Negatif sayilarin faktoriyeli hesaplanamaz.\n");
    }

    else

    {
        int sonuc = fact(sayi);
        printf("%d! = %d\n", sayi, sonuc);
    }

    return 0;
}
