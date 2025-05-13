#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {
    int sayi;
    printf("Fibonacci serisini hesaplamak istediðiniz terim sayýsýný girin: ");
    scanf("%d", &sayi);

    if (sayi < 0) {
        printf("Negatif sayýlar için Fibonacci hesaplanamaz.\n");
    } else {
        printf("Fibonacci Serisi:\n");
        for (int i = 0; i < sayi; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
