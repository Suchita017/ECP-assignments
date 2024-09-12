#include <stdio.h>

// Function prototype
void print_pascals_triangle(int rows);

int main() {
    int rows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    print_pascals_triangle(rows);

    return 0;
}

void print_pascals_triangle(int rows) {
    int i, j;
    int coef = 1;

    for (i = 0; i < rows; i++) {
       
        for (j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                coef = 1;
            } else {
                coef = coef * (i - j + 1) / j;
            }
            printf("%d ", coef);
        }
        printf("\n");
    }
}

