main() {

int agirlik[6] = {48, 32, 06, 24, 102, 34};

int *p;

p = agirlik; // D�KKAT, agirlik dizisinin adresi atan�yor

printf("%p\n", agirlik); // agirlik dizisinin adresini yaz, 0022FF20 yaz�l�r

printf("%p\n", p); // p de�i�keninin verisini yaz, 0022FF20 yaz�l�r

printf("%d\n", agirlik[0]); // Dizinin ilk eleman�n�n verisini yaz, 48 yaz�l�rprintf("%d\n", *p); // p de�i�keninde bulunan adresteki veriyi yaz, 48 yaz�l�rprintf("%d\n", agirlik[1]); // Dizinin ikinci eleman�n�n verisini yaz, 32 yaz�l�rprintf("%d\n", *++p);

// p de�i�kenindeki adresten bir sonraki adreste bulunan veriyi yaz, 32 yaz�l�r

return 0;

}
