#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *temp = NULL;
struct node *top = NULL;

void push(int sayi) {
    struct node* eleman = (struct node *)malloc(sizeof(struct node));

    if (top == NULL) {
        top = eleman;
        top->next = NULL;
        top->data = sayi;
    }
    else {
        eleman->next = top;
        top = eleman;
        top->data = sayi;
    }
}



void pop() {
    if (top == NULL) {
        printf("Yigin bos\n");
    }
    else {
        printf("%d Elemani Stackten Cikarildi \n", top->data);
        temp = top->next;
        free(top);
        top = temp;
    }
}

void print() {
    system("cls");
    if (top == NULL) {
        printf("Stack Bos\n");
    }
    else {
        temp = top;
        while (temp->next != NULL) {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        printf("%d \n", temp->data);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack bos\n");
    }
    else {
        printf("yigindaki en ust eleman: %d \n", top->data);
    }
}

int main() {
    int secim, sayi;
    while (1) {
        printf("Stack \n");
        printf("1---PUSH \n");
        printf("2---POP \n");
        printf("3---PRINT \n");
        printf("4---PEEK \n");
        printf("5---CIKIS \n");
        scanf("%d", &secim);
        switch (secim) {
        case 1:
            printf("Stacke Eklenecek sayi: ");
            scanf("%d", &sayi);
            push(sayi);
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            peek();
            break;


        }
    }
}
