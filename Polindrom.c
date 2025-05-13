#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Stack veri yap�s�
typedef struct {
    char data[MAX_LENGTH];
    int top;
} Stack;

// Stack operasyonlar�
void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char c) {
    if (stack->top < MAX_LENGTH - 1) {
        stack->data[++stack->top] = c;
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return '\0'; // Stack bo�sa null karakter d�nd�r
}

// C�mlenin palindrom olup olmad���n� kontrol eden fonksiyon
bool isPalindrome(char *sentence) {
    int length = strlen(sentence);
    Stack stack;
    initialize(&stack);

    // �lk yar�s�n� stack'e ekle
    for (int i = 0; i < length / 2; ++i) {
        push(&stack, sentence[i]);
    }

    // C�mle uzunlu�u tekse ortadaki karakteri atla
    if (length % 2 != 0) {
        ++length;
    }

    // Stack'ten ��kart�lan karakterlerle geri kalan� kar��la�t�r
    for (int i = length / 2; i < length; ++i) {
        char c = pop(&stack);
        if (c != sentence[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char sentence[MAX_LENGTH];

    printf("C�mleyi girin: ");
    fgets(sentence, MAX_LENGTH, stdin);

    // Sat�r sonu karakterini kald�r
    sentence[strcspn(sentence, "\n")] = '\0';

    if (isPalindrome(sentence)) {
        printf("Palindrom!\n");
    } else {
        printf("Palindrom de�il!\n");
    }

    return 0;
}

