#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to reverse a string
void reverse(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

// Function to convert an integer to a string based on a specified base
char* itoa(int value, char *string, int base) {
    // Handle base cases
    if (base < 2 || base > 36) {
        *string = '\0'; // Return empty string for invalid base
        return string;
    }

    // Handle zero value
    if (value == 0) {
        *string = '0';
        *(string + 1) = '\0';
        return string;
    }

    // Handle negative values for decimal and hexadecimal bases
    int isNegative = 0;
    if (value < 0 && base == 10) {
        isNegative = 1;
        value = -value;
    }

    // Convert the number to string
    char *ptr = string;
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (value != 0) {
        int remainder = value % base;
        *ptr++ = digits[remainder];
        value /= base;
    }

    // Add negative sign for negative numbers
    if (isNegative) {
        *ptr++ = '-';
    }

    // Null-terminate the string
    *ptr = '\0';

    // Reverse the string as the digits are added in reverse order
    reverse(string);

    return string;
}

int main() {
    char buffer[50];

    // Example usages
    printf("itoa(1234, buffer, 10) = %s\n", itoa(1234, buffer, 10)); // Decimal base
    printf("itoa(-1234, buffer, 10) = %s\n", itoa(-1234, buffer, 10)); // Decimal base with negative
    printf("itoa(255, buffer, 16) = %s\n", itoa(255, buffer, 16)); // Hexadecimal base
    printf("itoa(255, buffer, 2) = %s\n", itoa(255, buffer, 2)); // Binary base
    printf("itoa(1234, buffer, 8) = %s\n", itoa(1234, buffer, 8)); // Octal base

    return 0;
}

