#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define a union to store either a grade or a percentage
typedef union {
    char grade;       // Grade scheme (A, B, C)
    float percentage; // Percentage scheme
} Result;

// Define a structure to store student information
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    int standard;      // Standard of the student (1 to 12)
    Result result;     // Result either as grade or percentage
    int isGrade;       // 1 if grade, 0 if percentage
} Student;

// Function prototypes
void inputStudentInfo(Student *s);
void printStudentInfo(const Student *s);

int main() {
    Student students[3];

    // Input information for 3 students
    for (int i = 0; i < 3; ++i) {
        printf("Enter information for student %d:\n", i + 1);
        inputStudentInfo(&students[i]);
    }

    // Print information for 3 students
    for (int i = 0; i < 3; ++i) {
        printf("\nStudent %d information:\n", i + 1);
        printStudentInfo(&students[i]);
    }

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

    printf("Enter standard (1 to 12): ");
    scanf("%d", &s->standard);

    // Check if standard is valid
    if (s->standard < 1 || s->standard > 12) {
        printf("Invalid standard. Setting to 1.\n");
        s->standard = 1;
    }

    // Input result based on the standard
    if (s->standard <= 4) {
        printf("Enter grade (A, B, C): ");
        scanf(" %c", &s->result.grade);
        s->isGrade = 1;
    } else {
        printf("Enter percentage: ");
        scanf("%f", &s->result.percentage);
        s->isGrade = 0;
    }
}

// Function to print student information
void printStudentInfo(const Student *s) {
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Name: %s\n", s->name);
    printf("Standard: %d\n", s->standard);

    if (s->isGrade) {
        printf("Result (Grade): %c\n", s->result.grade);
    } else {
        printf("Result (Percentage): %.2f%%\n", s->result.percentage);
    }
}

