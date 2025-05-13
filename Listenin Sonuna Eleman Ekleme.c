#include <stdio.h>
#include <stdlib.h>

// Tek bağlı doğrusal liste düğüm yapısı tanımlaması
struct node {
    int data;
    struct node* next;
};

// Listenin sonuna eleman ekleyen fonksiyon
struct node* addlast(struct node* head, int key) {
    // Yeni bir düğüm oluştur ve veri ataması yap
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Bellek tahsisi hatası\n");
        exit(1);
    }
    temp->data = key;
    temp->next = NULL;

    // Eğer liste boşsa, yeni düğümü listenin başı yap
    if (head == NULL) {
        head = temp;
    } else {
        // Değilse, listenin sonuna kadar ilerle
        struct node* temp2 = head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }

        // Yeni düğümü listenin sonuna ekle
        temp2->next = temp;
    }

    return head;
}

// Listeyi ekrana yazdıran fonksiyon
void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // Liste başlangıcı

    int n, num;

    printf("Kaç adet sayı gireceksiniz? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Sayı %d: ", i + 1);
        scanf("%d", &num);
        head = addlast(head, num);
    }

    // Listeyi ekrana yazdır
    printf("Liste: ");
    printList(head);

    // Belleği temizle (serbest bırak)
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
