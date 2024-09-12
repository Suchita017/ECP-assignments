#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number > 0) {
        printf("%d is a Positive number.\n", number);
    } else if (number < 0) {
        printf("%d is a Negative number.\n", number);
    } else {
        printf("%d is Zero.\n", number);
    }

    return 0;
}

