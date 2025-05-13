#include <stdio.h>
#include <stdlib.h>

// Tek ba�l� do�rusal liste d���m yap�s� tan�mlamas�
struct node {
    int data;
    struct node* next;
};

void listinfo(struct node* head) {
    int i = 1;

    while (head != NULL) {
        printf("%d. Dugumunun Adresi = %p\n", i, (void*)head);
        printf("%d. Dugumunun Verisi = %d\n", i, head->data);
        printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi = %p\n\n", i, (void*)head->next);

        head = head->next;
        i++;
    }
}

int main() {
    // �rnek bir ba�l� liste olu�tur
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;

    struct node* node2 = (struct node*)malloc(sizeof(struct node));
    node2->data = 2;

    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    node3->data = 3;

    // D���mleri birbirine ba�la
    head->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // D���mlerin bilgilerini ekrana yazd�r
    listinfo(head);

    // Belle�i temizle (serbest b�rak)
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
