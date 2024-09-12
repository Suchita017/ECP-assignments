#include <stdio.h>

int main() {
    int num1, num2, temp;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("%d %% %d = ", num1, num2);

    while (num2 != 0) {
        temp = num1 % num2;
        printf("%d\n", temp);
        num1 = num2;
        num2 = temp;
        if (num2 != 0) {
            printf("%d %% %d = ", num1, num2);
        }
    }

    printf("GCD of %d and %d is %d\n", num1, num2, num1);

    return 0;
}

