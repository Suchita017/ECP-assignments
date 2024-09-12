//Write a program to find factorial of given number.

#include <stdio.h>

int main() 
{
    int num, i;
    long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number does not exist.\n");
        return 1;
    }

    for (i = num; i > 0; i--) {
        factorial *= i;
        if (i > 1) {
            printf("%d * ", i);
        } else {
            printf("%d = %lld\n", i, factorial);
        }
    }

    return 0;
	}
