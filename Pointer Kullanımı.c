
main() {
int agirlik = 10;

int *p;

p = &agirlik;

printf("%d\n", agirlik); // agirlik değişkeninin verisini yaz, 10 yazılır

printf("%p\n", &agirlik); // agirlik değişkeninin adresini yaz, 0022FF44 yazılır

printf("%p\n", p); // p değişkeninin verisini yaz, 0022FF44 yazılır

printf("%d\n", *p); // p değişkenindeki adresteki veriyi yaz, 10 yazılır

printf("%p\n", &p); // p değişkeninin adresini yaz, 0022FF40 yazılır

return 0;

}
