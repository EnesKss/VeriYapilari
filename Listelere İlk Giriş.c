

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





Tek ba�l� listelerin genel yap�s� a�a��da verilmi�tir. Konu anlat�l�rken daima bu temel yap� kullan�laca��ndanunutmamal�s�n�z.

struct node {
int data;
struct node *next;
};



Listenin ilk eleman� genellikle head olarak adland�r�l�r. head�den sonra di�er elemanlara eri�mek kolayd�r. Baz�
kaynaklarda listenin sonundaki eleman�n ismi tail olarak adland�r�lm��t�r. Fakat biz bu ismi notlar�m�zda
kullanmayaca��z.


