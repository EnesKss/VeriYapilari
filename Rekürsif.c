#include <stdio.h>

void hesapla(int x) {
    printf("%d", x); // �lk olarak x'i yazd�r
    if (x < 9) {
        hesapla(x + 1); // x 9'dan k���kse, x'i bir artt�rarak fonksiyonu tekrar �a��r
    }
    printf("%d", x); // Son olarak x'i tekrar yazd�r
}

int main() {
    hesapla(1);
    return 0;
}
