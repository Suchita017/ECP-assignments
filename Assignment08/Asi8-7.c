#include <stdio.h>

// Define a structure to store student information with bit-fields
typedef struct {
    unsigned int rollNumber;  // Assuming roll number can fit in an unsigned int
    unsigned int standard : 4; // Standard (1 to 12) - 4 bits
    unsigned int gender : 1;   // Gender (0 or 1) - 1 bit
    unsigned int age : 6;      // Age (0 to 32) - 6 bits (since 2^6 = 64, which is more than 32)
    char name[100];            // Name of the student
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
    scanf("%u", &s->rollNumber);

    printf("Enter standard (1 to 12): ");
    scanf("%u", &s->standard);

    // Ensure the standard is within the valid range
    if (s->standard < 1 || s->standard > 12) {
        printf("Invalid standard. Setting to 1.\n");
        s->standard = 1;
    }

    printf("Enter gender (0 for Female, 1 for Male): ");
    scanf("%u", &s->gender);

    // Ensure gender is within valid range
    if (s->gender > 1) {
        printf("Invalid gender. Setting to 0 (Female).\n");
        s->gender = 0;
    }

    printf("Enter age (0 to 32): ");
    scanf("%u", &s->age);

    // Ensure age is within valid range
    if (s->age > 32) {
        printf("Invalid age. Setting to 32.\n");
        s->age = 32;
    }

    // Clear input buffer before reading string
    while (getchar() != '\n');

    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    // Remove newline character if present
    s->name[strcspn(s->name, "\n")] = '\0';
}

// Function to print student information
void printStudentInfo(const Student *s) {
    printf("Roll Number: %u\n", s->rollNumber);
    printf("Standard: %u\n", s->standard);
    printf("Gender: %s\n", s->gender == 0 ? "Female" : "Male");
    printf("Age: %u\n", s->age);
    printf("Name: %s\n", s->name);
}

