#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if any command-line arguments are provided
    if (argc < 2) {
        printf("No names provided. Please provide names as command-line arguments.\n");
        return 1;
    }

    // Display the names
    printf("List of names:\n");
    for (int i = 1; i < argc; ++i) {
        printf("%d. %s\n", i, argv[i]);
    }

    return 0;
}

