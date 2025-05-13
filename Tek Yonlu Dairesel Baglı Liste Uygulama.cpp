#include <stdio.h>
#include <stdlib.h>

//Tek yonlu dairesel baglý liste ile musteri takip uygulamasý

struct musteri {
    int no;
    char ad[40];
    char urun[40];
    int ucret;
    char adres[40];
    struct musteri *next;
};

typedef struct musteri node;

node *ekle(node *head) {
    node *m1 = (node *)malloc(sizeof(node));
    printf("Musteri no: ");
    scanf("%d", &m1->no);
    printf("Musteri adi: ");
    scanf("%s", m1->ad);
    printf("Musteri urun: ");
    scanf("%s", m1->urun);
    printf("Musteri adresi: ");
    scanf("%s", m1->adres);

    if (head == NULL) {
        head = m1;
        head->next = head;
        printf("Liste olusturuldu ilk musteri eklendi \n");
    } else {
        node *p = head;
        while (p->next != head) {
            p = p->next;
        }
        m1->next = head;
        head = m1;
        p->next = head;
        printf("Listeye musteri eklendi. \n");
    }

    return head;
}

node *sil(node *head) {
    if (head == NULL) {
        printf("Liste bos , silinecek musteri yok \n");
    } else {
        int mNo;
        printf("silinecek musteri no: ");
        scanf("%d", &mNo);

        if (head->next == head && head->no == mNo) {
            free(head);
            head = NULL;
            printf("listede kalan son musteri silindi \n");
        } else if (head->next != head && head->no == mNo) {
            node *p = head;
            while (p->next != head) {
                p = p->next;
            }

            node *p2 = head->next;
            free(head);
            head = p2;
            p->next = head;
            printf("%d numarali musteri silindi \n", mNo);
        } else {
            node *p = head;
            node *p2 = head;
            while (p->next != head) {
                if (p->no == mNo) {
                    p2->next = p->next;
                    free(p);
                    printf("%d numarali musteri silindi \n", mNo);
                }
                p2 = p;
                p = p->next;
            }
            if (p->no == mNo) {
                p2->next = p->next;
                free(p);
                printf("%d numarali musteri silindi \n", mNo);
            }
        }
    }

    return head;
}

node *yazdir(node *head) {
    if (head == NULL) {
        printf("liste bos !!! \n");
    } else {
        node *p = head;
        do {
            printf("*************************** \n");
            printf("Musteri no: %d Adi: %s Urunu: %s  Ucreti: %d Adres: %s  \n", p->no, p->ad, p->urun, p->ucret, p->adres);
            p = p->next;
        } while (p != head);
    }

    return head;
}

node *ara(node *head) {
    if (head == NULL) {
        printf("liste bos \n");
    } else {
        int mNo;
        printf("musteri no: ");
        scanf("%d", &mNo);
        node *p = head;
        do {
            if (p->no == mNo) {
                printf("%d numarali musteri bilgileri \n", mNo);
                printf("adi    :  %s \n", p->ad);
                printf("urun   :  %s \n", p->urun);
                printf("ucret  :  %d \n", p->ucret);
                printf("adres  :  %s \n", p->adres);
            }
            p = p->next;
        } while (p != head);
    }

    return head;
}

node *toplamgelir(node *head) {
    int toplam = 0;
    if (head == NULL) {
        printf("liste bos!  \n");
    } else {
        node *p = head;
        do {
            toplam += p->ucret;
            p = p->next;
        } while (p != head);
        printf("toplam gelir : %d \n", toplam);
    }

    return head;
}

int main() {
    int secim;
    node *head = NULL;
    while (1) {
        printf("\n tek yonlu dairesel bagli liste ile musteri takip uygulamasi \n");
        printf("1-- ekle \n");
        printf("2-- sil \n");
        printf("3-- yazdir \n");
        printf("4-- ara \n");
        printf("5-- toplam gelir \n");
        printf("0-- cikis \n");
        printf("seciminizi yapiniz [0-5] \n");

        scanf("%d", &secim);
        switch (secim) {
            case 1:
                head = ekle(head);
                break;
            case 2:
                head = sil(head);
                break;
            case 3:
                head = yazdir(head);
                break;
            case 4:
                head = ara(head);
                break;
            case 5:
                head = toplamgelir(head);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("hatali secim !!! \n");
        }
    }

    return 0;
}

