#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int** allocateMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
void printMatrix(int** matrix, int rows, int cols);

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the matrix
    int** matrix = allocateMatrix(rows, cols);
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    printMatrix(matrix, rows, cols);

    // Free allocated memory
    freeMatrix(matrix, rows);

    return 0;
}

// Function to allocate memory for a 2-dimensional matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Free previously allocated memory before returning
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL; // Memory allocation failed
        }
    }

    return matrix;
}

// Function to free memory allocated for a 2-dimensional matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the array of pointers
}

// Function to print a 2-dimensional matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

