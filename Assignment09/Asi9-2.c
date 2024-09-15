#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    int ch;

    // Prompt the user for the filename
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file character by character and display its content
    printf("File content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

    return 0;
}


clear
