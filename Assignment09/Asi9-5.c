#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

// Define the Student structure
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function to write a student's record to a file
void writeStudentToFile(FILE *file, const Student *s) {
    fprintf(file, "%d\n%s\n%.2f\n", s->rollNumber, s->name, s->marks);
}

// Function to read a student's record from a file
void readStudentFromFile(FILE *file, Student *s) {
    fscanf(file, "%d\n", &s->rollNumber);
    fgets(s->name, MAX_NAME_LENGTH, file);
    // Remove the newline character if present
    s->name[strcspn(s->name, "\n")] = '\0';
    fscanf(file, "%f\n", &s->marks);
}

int main() {
    Student student1 = {101, "Alice", 88.5};
    Student student2;
    FILE *file;

    // Write student record to a file
    file = fopen("student_records.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    writeStudentToFile(file, &student1);
    fclose(file);

    // Read student record from the file
    file = fopen("student_records.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    readStudentFromFile(file, &student2);
    fclose(file);

    // Display the read student record
    printf("Student Record Read from File:\n");
    printf("Roll Number: %d\n", student2.rollNumber);
    printf("Name: %s\n", student2.name);
    printf("Marks: %.2f\n", student2.marks);

    return 0;
}

