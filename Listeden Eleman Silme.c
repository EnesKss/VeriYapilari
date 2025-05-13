struct node *sil(struct node *bas, int anahtar) {
    if (bas == NULL) {
        printf("Listede eleman yok\n");
        return bas;
    }

    struct node *gecici = bas;

    if (bas->data == anahtar) {
        bas = bas->next;
        free(gecici);
    } else if (gecici->next == NULL) {
        printf("Silmek istediðiniz veri bulunamadý.\n\n");
    } else {
        while (gecici->next->data != anahtar) {
            if (gecici->next->next == NULL) {
                printf("Silmek istediðiniz veri bulunamadý.\n\n");
                return bas;
            }
            gecici = gecici->next;
        }

        struct node *gecici2 = gecici->next;
        gecici->next = gecici->next->next;
        free(gecici2);
    }

    return bas;
}
