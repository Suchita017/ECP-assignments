#include <stdio.h>

int main() {
    char character;
    int number;

    printf("Enter a character: ");
    scanf(" %c", &character); 

    printf("Enter a number: ");
    scanf("%d", &number);

   
    for (int i = 0; i < number; i++) {
        printf("%c", character);
    }

    printf("\n");

    return 0;
}

