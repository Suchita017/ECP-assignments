#include <stdio.h>

void print_char_n_times(char character, int times);

int main() {
    char character;
    int times;

    printf("Enter a character: ");
    scanf(" %c", &character);

    printf("Enter the number of times to print the character: ");
    scanf("%d", &times);

    print_char_n_times(character, times);

    return 0;
}

void print_char_n_times(char character, int times) {
    for (int i = 0; i < times; i++) {
        printf("%c", character);
    }
    printf("\n");
}

