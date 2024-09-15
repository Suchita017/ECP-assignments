#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 10  // Define the maximum number of students

// Define a structure to store student information
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function prototypes
void inputStudentArray(Student students[], int count);
void printStudentArray(const Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;

    // Input the number of students
    printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Number of students exceeds the maximum allowed (%d).\n", MAX_STUDENTS);
        return 1;
    }

    // Input student information
    inputStudentArray(students, numStudents);

    // Print student information
    printStudentArray(students, numStudents);

    return 0;
}

// Function to input information for an array of students
void inputStudentArray(Student students[], int count) {
    for (int i = 0; i < count; ++i) {
        printf("Enter information for student %d:\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNumber);

        // Clear input buffer before reading string
        while (getchar() != '\n');

        printf("Enter name: ");
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        // Remove newline character if present
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);

        // Clear input buffer
        while (getchar() != '\n');
    }
}

// Function to print information for an array of students
void printStudentArray(const Student students[], int count) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < count; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}


