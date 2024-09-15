#include <stdio.h>

// Function to accept a 2-D array from the user
void acceptArray(int rows, int cols, int array[rows][cols]) {
    printf("Enter the elements of the %d x %d array:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

// Function to print a 2-D array
void printArray(int rows, int cols, int array[rows][cols]) {
    printf("The %d x %d array is:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int rows, cols;

    // Input the dimensions of the array
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare the array with the specified dimensions
    int array[rows][cols];

    // Accept the array elements from the user
    acceptArray(rows, cols, array);

    // Print the array
    printArray(rows, cols, array);

    return 0;
}

