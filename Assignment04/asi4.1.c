#include <stdio.h>
#include <math.h>

int sum_of_digits(int num);
int reverse_number(int num);
int is_palindrome(int num);
int is_armstrong(int num);

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int sum = sum_of_digits(number);
    int temp = number;
    while (temp > 0) {
        printf("%d", temp % 10);
        temp /= 10;
        if (temp > 0) printf(" + ");
    }
    printf(" = %d\n", sum);

    int reversed = reverse_number(number);
    printf("Reversed number: %d\n", reversed);

    if (is_palindrome(number)) {
        printf("%d is a numeric palindrome\n", number);
    } else {
        printf("%d is not a numeric palindrome\n", number);
    }

    if (is_armstrong(number)) {
        printf("%d is an Armstrong number\n", number);
    } else {
        printf("%d is not an Armstrong number\n", number);
    }

    return 0;
}

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int is_palindrome(int num) {
    return (num == reverse_number(num));
}

int is_armstrong(int num) {
    int original = num, sum = 0;
    int num_digits = (int)log10(num) + 1;
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, num_digits);
        num /= 10;
    }
    return (sum == original);
}

