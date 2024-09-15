#include <stdio.h>

// Function to swap two numbers using XOR operation
void swapUsingXOR(int *a, int *b) {
    // Check if the addresses are different to avoid swapping the same variable
    if (a != b) {
        *a = *a ^ *b; // Step 1: XOR the values and store in *a
        *b = *a ^ *b; // Step 2: XOR the new value of *a with *b to get the original value of *a
        *a = *a ^ *b; // Step 3: XOR the new value of *b with *a to get the original value of *b
    }
}

int main() {
    int x, y;

    // Input the numbers from user
    printf("Enter two integers:\n");
    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    // Display values before swapping
    printf("Before swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    // Swap the numbers
    swapUsingXOR(&x, &y);

    // Display values after swapping
    printf("After swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}

