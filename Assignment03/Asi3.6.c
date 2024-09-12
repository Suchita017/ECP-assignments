#include <stdio.h>

int main() {
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("All factors: ");
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            printf("%d", i);
            if (i < num / 2) {
                printf(", ");
            }
        }
    }
    printf("\n");

    return 0;
}

