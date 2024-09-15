#include <stdio.h>

// Function to reverse array elements
void reverseArray(float arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        float temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
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
    
    inputArray(marks, size);

    printf("Original array:\n");
    printArray(marks, size);

    reverseArray(marks, size);

    printf("Reversed array:\n");
    printArray(marks, size);

    return 0;
}

