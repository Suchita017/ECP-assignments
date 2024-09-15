#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDENTS 5
#define NAME_LENGTH 50

// Function prototypes
void inputNames(char *names[NUM_STUDENTS]);
void printNames(char *names[NUM_STUDENTS]);
void sortNames(char *names[NUM_STUDENTS]);

int main() {
    char *studentNames[NUM_STUDENTS];

    // Allocate memory for each name
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        studentNames[i] = malloc(NAME_LENGTH * sizeof(char));
        if (studentNames[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    // Input names
    inputNames(studentNames);

    // Print names before sorting
    printf("Names before sorting:\n");
    printNames(studentNames);

    // Sort names
    sortNames(studentNames);

    // Print names after sorting
    printf("Names after sorting:\n");
    printNames(studentNames);

    // Free allocated memory
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        free(studentNames[i]);
    }

    return 0;
}

// Function to input names from the user
void inputNames(char *names[NUM_STUDENTS]) {
    printf("Enter the names of %d students:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("Name %d: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);
        // Remove newline character if present
        names[i][strcspn(names[i], "\n")] = '\0';
    }
}

// Function to print names
void printNames(char *names[NUM_STUDENTS]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

// Function to sort names in alphabetical order
void sortNames(char *names[NUM_STUDENTS]) {
    char *temp;
    for (int i = 0; i < NUM_STUDENTS - 1; ++i) {
        for (int j = i + 1; j < NUM_STUDENTS; ++j) {
            if (strcmp(names[i], names[j]) > 0) {
                // Swap names[i] and names[j]
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

