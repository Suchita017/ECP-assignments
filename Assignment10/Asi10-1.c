#include <stdio.h>

// Function to count the number of '1' bits in an integer
int countSetBits(unsigned int num) {
    int count = 0;
    
    while (num) {
        count += num & 1;  // Increment count if the last bit is 1
        num >>= 1;         // Right shift the number by 1 bit
    }
    
    return count;
}

int main() {
    unsigned int number;
    
    // Input the number from user
    printf("Enter a number: ");
    scanf("%u", &number);
    
    // Count the number of '1' bits
    int setBits = countSetBits(number);
    
    // Output the result
    printf("Number of '1' bits in %u: %d\n", number, setBits);
    
    return 0;
}

