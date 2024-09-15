#include <stdio.h>
#include <string.h>

// Function to convert an integer to a Roman numeral
void intToRoman(int num, char *roman) {
    // Define Roman numeral symbols and their values
    struct {
        int value;
        const char *symbol;
    } romanValues[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    int i = 0;
    roman[0] = '\0'; // Initialize empty string

    // Convert integer to Roman numeral
    for (i = 0; i < sizeof(romanValues) / sizeof(romanValues[0]); i++) {
        while (num >= romanValues[i].value) {
            strcat(roman, romanValues[i].symbol);
            num -= romanValues[i].value;
        }
    }
}

int main() {
    char roman[20];
    int number = 1987;

    intToRoman(number, roman);
    printf("The Roman numeral of %d is %s\n", number, roman);

    return 0;
}

