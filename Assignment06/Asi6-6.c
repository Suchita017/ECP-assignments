#include <stdio.h>
#include <stdlib.h>

char* itoa(int value, char *string, int base) {
    // Validate base
    if (base < 2 || base > 36) {
        return NULL; // Base out of range
    }

    // Handle 0 explicitly
    if (value == 0) {
        string[0] = '0';
        string[1] = '\0';
        return string;
    }

    char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char buffer[33]; // Buffer to hold the number in reverse
    int i = 0;
    int is_negative = 0;

    // Handle negative numbers if base is 10
    if (value < 0 && base == 10) {
        is_negative = 1;
        value = -value;
    }

    // Convert number to string in reverse order
    while (value != 0) {
        buffer[i++] = digits[value % base];
        value /= base;
    }

    // Add negative sign for base 10 if needed
    if (is_negative) {
        buffer[i++] = '-';
    }

    // Add null terminator
    buffer[i] = '\0';

    // Reverse the string to get the correct result
    int j;
    for (j = 0; j < i; j++) {
        string[j] = buffer[i - j - 1];
    }
    string[j] = '\0';

    return string;
}

int main() {
    char buffer[33];
    int number = -255;
    int base = 16;

    itoa(number, buffer, base);
    printf("The number in base %d is: %s\n", base, buffer);

    return 0;
}

