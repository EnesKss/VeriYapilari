//Bu �rnekte ilk olarak listeyi olu�turaca��z, ard�ndan eleman ekleme yapaca��z.

#include <stdio.h>
#include <stdlib.h>

// Ba�l� liste d���m yap�s� tan�mlamas�
struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL; // Ba�l� listenin ba�lang�c�

    // �lk d���m� olu�tur ve veri atamas� yap
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Bellek tahsisi hatas�\n");
        return 1;
    }
    head->data = 1;
    head->next = NULL;

    // �kinci d���m� olu�tur ve veri atamas� yap
    head->next = (struct node*)malloc(sizeof(struct node));
    if (head->next == NULL) {
        printf("Bellek tahsisi hatas�\n");
        return 1;
    }
    head->next->data = 3;
    head->next->next = NULL;

    // Belle�i temizle (serbest b�rak)
    free(head->next);
    free(head);

    return 0;
}
