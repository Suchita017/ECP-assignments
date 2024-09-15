#include <stdio.h>
#include <stdint.h>

// Function to check and set even parity
uint8_t checkAndSetEvenParity(uint8_t byte) {
    // Count the number of '1' bits
    int count = 0;
    uint8_t temp = byte;

    while (temp) {
        count += temp & 1;
        temp >>= 1;
    }

    // Check if the count is even or odd
    if (count % 2 == 0) {
        // Even parity; return the byte as is
        return byte;
    } else {
        // Odd parity; set the MSB to 1 to make the parity even
        return byte | 0x80; // 0x80 is 10000000 in binary
    }
}

int main() {
    uint8_t byte;

    // Input the byte from user
    printf("Enter a byte value (0-255): ");
    scanf("%hhu", &byte);

    // Check and set even parity
    uint8_t result = checkAndSetEvenParity(byte);

    // Display the result
    printf("Original byte: %u (0x%02X)\n", byte, byte);
    printf("Byte with even parity: %u (0x%02X)\n", result, result);

    return 0;
}

