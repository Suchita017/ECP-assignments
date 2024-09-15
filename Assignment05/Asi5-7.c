#include <stdio.h>

// Function to perform selection sort on an array
void selectionSort(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        float temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform bubble sort on an array
void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
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
    float arr[size];
    
    inputArray(arr, size);
    
    int choice;
    printf("Choose sorting method:\n1. Selection Sort\n2. Bubble Sort\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            selectionSort(arr, size);
            break;
        case 2:
            bubbleSort(arr, size);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    
    printf("Sorted array:\n");
    printArray(arr, size);
    
    return 0;
}

