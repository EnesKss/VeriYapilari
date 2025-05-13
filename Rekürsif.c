#include <stdio.h>

void hesapla(int x) {
    printf("%d", x); // Ýlk olarak x'i yazdýr
    if (x < 9) {
        hesapla(x + 1); // x 9'dan küçükse, x'i bir arttýrarak fonksiyonu tekrar çaðýr
    }
    printf("%d", x); // Son olarak x'i tekrar yazdýr
}

int main() {
    hesapla(1);
    return 0;
}
