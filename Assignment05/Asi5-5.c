#include <stdio.h>

// Function to find the maximum and minimum elements in an array
void findMaxMin(float arr[], int size, float *max, float *min) {
    // Initialize max and min with the first element
    *max = arr[0];
    *min = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

// Function to accept array elements from the user
void inputArray(float arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
}

// Function to print array elements
void printArray(float arr[], int size) {
    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %.2f\n", i + 1, arr[i]);
    }
}

int main() {
    int size = 5;
    float marks[size];
    float max, min;
    
    inputArray(marks, size);

    printf("Array elements:\n");
    printArray(marks, size);

    findMaxMin(marks, size, &max, &min);

    printf("Maximum element: %.2f\n", max);
    printf("Minimum element: %.2f\n", min);

    return 0;
}

