#include <stdio.h>

// Function to display the given number in binary format
void displayBinary(unsigned int num) {
    // Find the number of bits in an integer (assumed to be 32-bit for this example)
    int bits = sizeof(num) * 8;
    int leadingZeroes = 1;
    
    // Loop through each bit from the most significant bit to the least significant bit
    for (int i = bits - 1; i >= 0; i--) {
        // Extract the bit at position i
        int bit = (num >> i) & 1;
        
        // Print '1' or '0' based on the bit value
        if (bit == 1) {
            leadingZeroes = 0; // Found the first '1', so no more leading zeroes
        }
        
        // Print the bit only if leadingZeroes is 0 (i.e., we have started printing significant bits)
        if (!leadingZeroes) {
            printf("%d", bit);
        }
    }
    
    // If all bits are zero, print '0'
    if (leadingZeroes) {
        printf("0");
    }
    
    printf("\n");
}

int main() {
    unsigned int number;
    
    // Input the number from user
    printf("Enter a number: ");
    scanf("%u", &number);
    
    // Display the number in binary format
    printf("Binary representation of %u: ", number);
    displayBinary(number);
    
    return 0;
}

