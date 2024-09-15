#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    // Check if any command-line arguments are provided
    if (argc < 2) {
        printf("No names provided. Please provide names as command-line arguments.\n");
        return 1;
    }

    // Sort the command-line arguments (excluding the program name itself)
    qsort(&argv[1], argc - 1, sizeof(char *), compareStrings);

    // Display the sorted names
    printf("List of names in sorted order:\n");
    for (int i = 1; i < argc; ++i) {
        printf("%d. %s\n", i, argv[i]);
    }

    return 0;
}

