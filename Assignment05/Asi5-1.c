#include <stdio.h>

int main() {
    // Declare variables
    float marks[5];
    float total = 0.0, average;
    int i;

    // Input marks for five subjects
    printf("Enter the marks for five subjects:\n");
    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Calculate total
    for (i = 0; i < 5; i++) {
        total += marks[i];
    }

    // Calculate average
    average = total / 5;

    // Display results
    printf("Total marks: %.2f\n", total);
    printf("Average marks: %.2f\n", average);

    return 0;
}

