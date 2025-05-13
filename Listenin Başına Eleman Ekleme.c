#include <stdio.h>
#include <stdlib.h>

// Tek baðlý doðrusal liste düðüm yapýsý tanýmlamasý
struct node {
    int data;
    struct node* next;
};

// Listenin baþýna eleman ekleyen fonksiyon
struct node* addhead(struct node* head, int key) {
    // Yeni bir düðüm oluþtur ve veri atamasý yap
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Bellek tahsisi hatasý\n");
        exit(1);
    }
    temp->data = key;

    // Yeni düðümün next'i, mevcut baþý (head) göstersin
    temp->next = head;

    // Yeni düðüm, listenin yeni baþý (head) olsun
    head = temp;

    return head;
}

// Listeyi ekrana yazdýran fonksiyon
void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // Liste baþlangýcý

    int n, num;

    printf("Kaç adet sayý gireceksiniz? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Sayý %d: ", i + 1);
        scanf("%d", &num);
        head = addhead(head, num);
    }

    // Listeyi ekrana yazdýr
    printf("Liste: ");
    printList(head);

    return 0;
}
