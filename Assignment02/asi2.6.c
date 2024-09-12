#include <stdio.h>

int main() {
    int number, originalNumber, reversedNumber = 0, remainder;

    printf("Enter a 5-digit number: ");
    scanf("%d", &number);

    originalNumber = number;

    if (number < 10000 || number > 99999) {
        printf("Error: The number is not a 5-digit number.\n");
    } else {
        while (number != 0) {
            remainder = number % 10;
            reversedNumber = reversedNumber * 10 + remainder;
            number = number / 10;
        }

        if (reversedNumber == originalNumber) {
            printf("%d is a Palindrome.\n", originalNumber);
        } else {
            printf("%d is not a Palindrome.\n", originalNumber);
        }
    }

    return 0;
}

