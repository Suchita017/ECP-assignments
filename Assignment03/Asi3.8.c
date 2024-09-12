#include <stdio.h>

int main() {
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("%d = ", num);

    for (i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            printf("%d", i);
            num /= i;
            if (num > 1) {
                printf(" * ");
            }
        }
    }

    if (num > 1) {
        printf("%d", num);
    }

    printf("\n");

    return 0;
}

