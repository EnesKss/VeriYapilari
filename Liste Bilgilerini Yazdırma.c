#include <stdio.h>
#include <stdlib.h>

// Tek baðlý doðrusal liste düðüm yapýsý tanýmlamasý
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
    // Örnek bir baðlý liste oluþtur
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;

    struct node* node2 = (struct node*)malloc(sizeof(struct node));
    node2->data = 2;

    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    node3->data = 3;

    // Düðümleri birbirine baðla
    head->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Düðümlerin bilgilerini ekrana yazdýr
    listinfo(head);

    // Belleði temizle (serbest býrak)
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
