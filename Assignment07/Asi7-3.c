#include <stdio.h>

#define SIZE 3

// Function prototypes
void inputMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
int sumOfRow(int matrix[SIZE][SIZE], int row);
int sumOfColumn(int matrix[SIZE][SIZE], int col);

int main() {
    int matrix[SIZE][SIZE];
    int row, col;

    // Input matrix
    inputMatrix(matrix);

    // Print matrix
    printf("Matrix:\n");
    printMatrix(matrix);

    // Calculate and print sum of a specific row
    printf("Enter the row index (0 to %d) to calculate the sum: ", SIZE - 1);
    scanf("%d", &row);
    if (row >= 0 && row < SIZE) {
        printf("Sum of elements in row %d: %d\n", row, sumOfRow(matrix, row));
    } else {
        printf("Invalid row index.\n");
    }

    // Calculate and print sum of a specific column
    printf("Enter the column index (0 to %d) to calculate the sum: ", SIZE - 1);
    scanf("%d", &col);
    if (col >= 0 && col < SIZE) {
        printf("Sum of elements in column %d: %d\n", col, sumOfColumn(matrix, col));
    } else {
        printf("Invalid column index.\n");
    }

    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[SIZE][SIZE]) {
    printf("Enter elements for the %d x %d matrix:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of elements in a given row
int sumOfRow(int matrix[SIZE][SIZE], int row) {
    int sum = 0;
    for (int j = 0; j < SIZE; ++j) {
        sum += matrix[row][j];
    }
    return sum;
}

// Function to calculate the sum of elements in a given column
int sumOfColumn(int matrix[SIZE][SIZE], int col) {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += matrix[i][col];
    }
    return sum;
}

