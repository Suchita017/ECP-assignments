#include <stdio.h>

// Function to remove duplicate elements from an array
int removeDuplicates(float arr[], int size) {
    if (size == 0) return 0;

    int uniqueCount = 0;
    
    // Traverse the array and check for duplicates
    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        // If no duplicate found, add element to unique list
        if (j == uniqueCount) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }

    return uniqueCount;
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
    int size = 10; // Example size, can be adjusted
    float arr[size];
    
    inputArray(arr, size);

    printf("Original array:\n");
    printArray(arr, size);

    int newSize = removeDuplicates(arr, size);

    printf("Array after removing duplicates:\n");
    printArray(arr, newSize);

    printf("Number of unique elements: %d\n", newSize);

    return 0;
}

