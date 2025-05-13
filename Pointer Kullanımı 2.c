main() {

int agirlik[6] = {48, 32, 06, 24, 102, 34};

int *p;

p = agirlik; // DÝKKAT, agirlik dizisinin adresi atanýyor

printf("%p\n", agirlik); // agirlik dizisinin adresini yaz, 0022FF20 yazýlýr

printf("%p\n", p); // p deðiþkeninin verisini yaz, 0022FF20 yazýlýr

printf("%d\n", agirlik[0]); // Dizinin ilk elemanýnýn verisini yaz, 48 yazýlýrprintf("%d\n", *p); // p deðiþkeninde bulunan adresteki veriyi yaz, 48 yazýlýrprintf("%d\n", agirlik[1]); // Dizinin ikinci elemanýnýn verisini yaz, 32 yazýlýrprintf("%d\n", *++p);

// p deðiþkenindeki adresten bir sonraki adreste bulunan veriyi yaz, 32 yazýlýr

return 0;

}
