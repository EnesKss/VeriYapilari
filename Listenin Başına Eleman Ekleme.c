#include <stdio.h>
#include <stdlib.h>

// Tek ba�l� do�rusal liste d���m yap�s� tan�mlamas�
struct node {
    int data;
    struct node* next;
};

// Listenin ba��na eleman ekleyen fonksiyon
struct node* addhead(struct node* head, int key) {
    // Yeni bir d���m olu�tur ve veri atamas� yap
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Bellek tahsisi hatas�\n");
        exit(1);
    }
    temp->data = key;

    // Yeni d���m�n next'i, mevcut ba�� (head) g�stersin
    temp->next = head;

    // Yeni d���m, listenin yeni ba�� (head) olsun
    head = temp;

    return head;
}

// Listeyi ekrana yazd�ran fonksiyon
void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // Liste ba�lang�c�

    int n, num;

    printf("Ka� adet say� gireceksiniz? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Say� %d: ", i + 1);
        scanf("%d", &num);
        head = addhead(head, num);
    }

    // Listeyi ekrana yazd�r
    printf("Liste: ");
    printList(head);

    return 0;
}
