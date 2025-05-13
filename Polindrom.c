#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

// Stack veri yapýsý
typedef struct {
    char data[MAX_LENGTH];
    int top;
} Stack;

// Stack operasyonlarý
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
    return '\0'; // Stack boþsa null karakter döndür
}

// Cümlenin palindrom olup olmadýðýný kontrol eden fonksiyon
bool isPalindrome(char *sentence) {
    int length = strlen(sentence);
    Stack stack;
    initialize(&stack);

    // Ýlk yarýsýný stack'e ekle
    for (int i = 0; i < length / 2; ++i) {
        push(&stack, sentence[i]);
    }

    // Cümle uzunluðu tekse ortadaki karakteri atla
    if (length % 2 != 0) {
        ++length;
    }

    // Stack'ten çýkartýlan karakterlerle geri kalaný karþýlaþtýr
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

    printf("Cümleyi girin: ");
    fgets(sentence, MAX_LENGTH, stdin);

    // Satýr sonu karakterini kaldýr
    sentence[strcspn(sentence, "\n")] = '\0';

    if (isPalindrome(sentence)) {
        printf("Palindrom!\n");
    } else {
        printf("Palindrom deðil!\n");
    }

    return 0;
}

