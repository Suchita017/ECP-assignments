#include <stdio.h>
#include <stdlib.h>

// Function to copy contents from source file to destination file
void copyFileContents(FILE *src, FILE *dest) {
    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
}

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFilename[100], destinationFilename[100];
    char userInput[100];
    char ch;

    // Input source and destination filenames
    printf("Enter the source filename: ");
    scanf("%s", sourceFilename);

    printf("Enter the destination filename: ");
    scanf("%s", destinationFilename);

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

