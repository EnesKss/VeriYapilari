//Bu örnekte ilk olarak listeyi oluþturacaðýz, ardýndan eleman ekleme yapacaðýz.

#include <stdio.h>
#include <stdlib.h>

// Baðlý liste düðüm yapýsý tanýmlamasý
struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL; // Baðlý listenin baþlangýcý

    // Ýlk düðümü oluþtur ve veri atamasý yap
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Bellek tahsisi hatasý\n");
        return 1;
    }
    head->data = 1;
    head->next = NULL;

    // Ýkinci düðümü oluþtur ve veri atamasý yap
    head->next = (struct node*)malloc(sizeof(struct node));
    if (head->next == NULL) {
        printf("Bellek tahsisi hatasý\n");
        return 1;
    }
    head->next->data = 3;
    head->next->next = NULL;

    // Belleði temizle (serbest býrak)
    free(head->next);
    free(head);

    return 0;
}
