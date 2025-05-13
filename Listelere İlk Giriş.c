

struct complex {

int real;
int im;
}
struct complex a, b;




typedef struct {
int real;

int im;

} complex;

complex a, b;





Tek baðlý listelerin genel yapýsý aþaðýda verilmiþtir. Konu anlatýlýrken daima bu temel yapý kullanýlacaðýndanunutmamalýsýnýz.

struct node {
int data;
struct node *next;
};



Listenin ilk elemaný genellikle head olarak adlandýrýlýr. head’den sonra diðer elemanlara eriþmek kolaydýr. Bazý
kaynaklarda listenin sonundaki elemanýn ismi tail olarak adlandýrýlmýþtýr. Fakat biz bu ismi notlarýmýzda
kullanmayacaðýz.


