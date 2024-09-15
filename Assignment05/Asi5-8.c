#include <stdio.h>

// Function to perform linear search in an array
int linearSearch(float arr[], int size, float target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the found element
        }
    }
    return -1;  // Return -1 if the element is not found
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
    float arr[size];
    
    inputArray(arr, size);

    printf("Array elements:\n");
    printArray(arr, size);

    float target;
    printf("Enter the number to search for: ");
    scanf("%f", &target);

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element %.2f found at index %d.\n", target, index);
    } else {
        printf("Element %.2f not found in the array.\n", target);
    }

    return 0;
}

