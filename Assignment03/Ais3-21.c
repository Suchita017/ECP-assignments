#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

void displayNextFivePrimes(int start) {
    int count = 0;
    int num = start + 1;

    while (count < 5) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int main() {
    int input;

    printf("Enter a number: ");
    scanf("%d", &input);

    displayNextFivePrimes(input);

    return 0;
}

