#include <stdio.h>

int main() {
    int number;

    // Accept a number from the user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the number is even or odd
    if (number % 2 == 0) {
        printf("%d is an Even number.\n", number);
    } else {
        printf("%d is an Odd number.\n", number);
    }

    return 0;
}

