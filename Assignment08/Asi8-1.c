#include <stdio.h>

#define MAX_NAME_LENGTH 100

// Define a structure to store student information
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function prototypes
void inputStudentInfo(Student *s);
void printStudentInfo(const Student *s);

int main() {
    Student student;

    // Input student information
    inputStudentInfo(&student);

    // Print student information
    printStudentInfo(&student);

    return 0;
}

// Function to input student information from the user
void inputStudentInfo(Student *s) {
    printf("Enter roll number: ");
    scanf("%d", &s->rollNumber);

    // Clear input buffer before reading string
    while (getchar() != '\n');

    printf("Enter name: ");
    fgets(s->name, MAX_NAME_LENGTH, stdin);
    // Remove newline character if present
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("Enter marks: ");
    scanf("%f", &s->marks);
}

// Function to print student information
void printStudentInfo(const Student *s) {
    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n", s->marks);
}

