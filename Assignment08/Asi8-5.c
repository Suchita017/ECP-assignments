#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 10

// Define a structure to store student information
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function prototypes
void inputStudentArray(Student students[], int count);
void printStudentArray(const Student students[], int count);
void sortByRollNumber(Student students[], int count);
void sortByName(Student students[], int count);
int compareByRollNumber(const void *a, const void *b);
int compareByName(const void *a, const void *b);

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

    // Print unsorted student information
    printf("\nUnsorted student information:\n");
    printStudentArray(students, numStudents);

    // Sort and print by roll number
    sortByRollNumber(students, numStudents);
    printf("\nStudent information sorted by roll number:\n");
    printStudentArray(students, numStudents);

    // Sort and print by name
    sortByName(students, numStudents);
    printf("\nStudent information sorted by name:\n");
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
    for (int i = 0; i < count; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

// Function to sort students by roll number
void sortByRollNumber(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareByRollNumber);
}

// Function to sort students by name
void sortByName(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareByName);
}

// Comparison function for sorting by roll number
int compareByRollNumber(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return studentA->rollNumber - studentB->rollNumber;
}

// Comparison function for sorting by name
int compareByName(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return strcmp(studentA->name, studentB->name);
}

