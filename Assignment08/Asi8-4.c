#include <stdio.h>
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
Student* searchByRollNumber(const Student students[], int count, int rollNumber);
Student* searchByName(const Student students[], int count, const char* name);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;
    int rollNumberToSearch;
    char nameToSearch[MAX_NAME_LENGTH];
    Student* foundStudent;

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

    // Search by roll number
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNumberToSearch);

    foundStudent = searchByRollNumber(students, numStudents, rollNumberToSearch);
    if (foundStudent != NULL) {
        printf("Student found:\n");
        printStudentArray(foundStudent, 1);
    } else {
        printf("Student with roll number %d not found.\n", rollNumberToSearch);
    }

    // Search by name
    while (getchar() != '\n');  // Clear the newline character from input buffer

    printf("\nEnter name to search: ");
    fgets(nameToSearch, MAX_NAME_LENGTH, stdin);
    // Remove newline character if present
    nameToSearch[strcspn(nameToSearch, "\n")] = '\0';

    foundStudent = searchByName(students, numStudents, nameToSearch);
    if (foundStudent != NULL) {
        printf("Student found:\n");
        printStudentArray(foundStudent, 1);
    } else {
        printf("Student with name '%s' not found.\n", nameToSearch);
    }

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

// Function to search for a student by roll number
Student* searchByRollNumber(const Student students[], int count, int rollNumber) {
    for (int i = 0; i < count; ++i) {
        if (students[i].rollNumber == rollNumber) {
            return (Student*)&students[i];  // Return pointer to the found student
        }
    }
    return NULL;  // Student not found
}

// Function to search for a student by name
Student* searchByName(const Student students[], int count, const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(students[i].name, name) == 0) {
            return (Student*)&students[i];  // Return pointer to the found student
        }
    }
    return NULL;  // Student not found
}

