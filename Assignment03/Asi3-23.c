#include <stdio.h>

// Function to print Pascal's Triangle
void printPascalsTriangle(int n) {
    
    int triangle[n][n];

   
    for (int i = 0; i < n; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }

    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

  
    for (int i = 0; i < n; i++) {
    
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }

     
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int n;

   
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

   
    printPascalsTriangle(n);

    return 0;
}

