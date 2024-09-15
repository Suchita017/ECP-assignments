#include <stdio.h>
#include <ctype.h>

// Function to check if the given character is an alphabet
// and perform a bitwise XOR operation with 32 if it is
void checkAndXOR(char ch) {
    if (isalpha(ch)) { // Check if the character is an alphabetic letter
        // Perform XOR with 32 (0x20)
        char result = ch ^ 32;
        printf("Original character: %c (ASCII: %d)\n", ch, ch);
        printf("Character after XOR with 32: %c (ASCII: %d)\n", result, result);
    } else {
        printf("The character '%c' is not an alphabet.\n", ch);
    }
}

int main() {
    char ch;

    // Input the character from user
    printf("Enter a character: ");
    scanf(" %c", &ch); // Space before %c to ignore any leading whitespace

    // Check and perform XOR operation
    checkAndXOR(ch);

    return 0;
}

