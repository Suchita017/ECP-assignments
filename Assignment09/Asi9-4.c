#include <stdio.h>
#include <stdlib.h>

// Function to copy contents from source file to destination file
void copyFileContents(FILE *src, FILE *dest) {
    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char *sourceFilename, *destinationFilename;
    char ch;
    char userInput[100];

    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    // Get filenames from command-line arguments
    sourceFilename = argv[1];
    destinationFilename = argv[2];

    // Open the source file in read mode
    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationFilename, "w");
    if (destinationFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    copyFileContents(sourceFile, destinationFile);

    // Close files after copying
    fclose(sourceFile);
    fclose(destinationFile);

    // Reopen the destination file in read mode to display its contents
    destinationFile = fopen(destinationFilename, "r");
    if (destinationFile == NULL) {
        perror("Error reopening destination file");
        return 1;
    }

    // Display the contents of the destination file
    printf("Contents of the destination file:\n");
    while ((ch = fgetc(destinationFile)) != EOF) {
        putchar(ch);
    }
    fclose(destinationFile);

    // Open the destination file in append mode to accept user input
    destinationFile = fopen(destinationFilename, "a");
    if (destinationFile == NULL) {
        perror("Error opening destination file for appending");
        return 1;
    }

    // Accept data from the user and write it to the destination file
    printf("\nEnter data to append to the destination file (end input with an EOF signal, usually Ctrl+D):\n");
    while (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        fputs(userInput, destinationFile);
    }
    fclose(destinationFile);

    printf("Data has been appended to the destination file.\n");

    return 0;
}

