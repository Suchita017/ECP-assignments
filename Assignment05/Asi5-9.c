#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(float arr[], int size, float target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    
    return -1;  // Target not found
}

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
    
    // Sort the array before performing binary search
    selectionSort(arr, size);
    
    printf("Sorted array:\n");
    printArray(arr, size);

    float target;
    printf("Enter the number to search for: ");
    scanf("%f", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("Element %.2f found at index %d.\n", target, index);
    } else {
        printf("Element %.2f not found in the array.\n", target);
    }

    return 0;
}

