//Write a program to find factorial of given number.
//Input: 5
//Output: 1 * 2 * 3 * 4 * 5 = 120

#include <stdio.h>

int main() {
    int num, i;
    long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number does not exist.\n");
        return 1;
    }

    for (i = 1; i <= num; i++) {
        factorial *= i;
        if (i < num) {
            printf("%d * ", i);
        } else {
            printf("%d = %lld\n", i, factorial);
        }
    }

    return 0;
}

