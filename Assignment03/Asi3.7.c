#include <stdio.h>

int main() {
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Output:\n");
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            printf("%d * %d = %d\n", i, num / i, num);
        }
    }

    return 0;
}

