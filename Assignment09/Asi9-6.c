#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define DATABASE_FILE "student_database.dat"

// Enumeration for menu options
typedef enum {
    WRITE_RECORD = 1,
    READ_RECORD,
    SEARCH_BY_ROLL,
    SEARCH_BY_NAME,
    MODIFY_RECORD,
    REMOVE_RECORD,
    EXIT
} MenuOption;

// Define the Student structure
typedef struct {
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    float marks;
} Student;

// Function prototypes
void writeStudentToFile();
void readStudentFromFile();
void searchStudentByRollNumber();
void searchStudentByName();
void modifyStudentRecord();
void removeStudentRecord();
void displayStudent(const Student *s);

int main() {
    MenuOption option;
    do {
        // Display menu
        printf("\nStudent Database Menu:\n");
        printf("1. Write student record to file\n");
        printf("2. Read student record from file\n");
        printf("3. Search student record by roll number\n");
        printf("4. Search student record by name\n");
        printf("5. Modify student record\n");
        printf("6. Remove student record\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Perform the selected operation
        switch (option) {
            case WRITE_RECORD:
                writeStudentToFile();
                break;
            case READ_RECORD:
                readStudentFromFile();
                break;
            case SEARCH_BY_ROLL:
                searchStudentByRollNumber();
                break;
            case SEARCH_BY_NAME:
                searchStudentByName();
                break;
            case MODIFY_RECORD:
                modifyStudentRecord();
                break;
            case REMOVE_RECORD:
                removeStudentRecord();
                break;
            case EXIT:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != EXIT);

    return 0;
}

// Function to write a student's record to a binary file
void writeStudentToFile() {
    FILE *file;
    Student s;

    file = fopen(DATABASE_FILE, "ab");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s.rollNumber);
    getchar();  // Consume newline character left by scanf

    printf("Enter name: ");
    fgets(s.name, MAX_NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';  // Remove newline character

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record written to file.\n");
}

// Function to read all student records from a binary file
void readStudentFromFile() {
    FILE *file;
    Student s;

    file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Student records:\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        displayStudent(&s);
    }

    fclose(file);
}

// Function to search for a student's record by roll number
void searchStudentByRollNumber() {
    FILE *file;
    Student s;
    int rollNumber;
    int found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNumber == rollNumber) {
            displayStudent(&s);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }

    fclose(file);
}

// Function to search for a student's record by name
void searchStudentByName() {
    FILE *file;
    Student s;
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter name to search: ");
    getchar();  // Consume newline character left by scanf
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    while (fread(&s, sizeof(Student), 1, file)) {
        if (strcmp(s.name, name) == 0) {
            displayStudent(&s);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name %s not found.\n", name);
    }

    fclose(file);
}

// Function to modify a student's record
void modifyStudentRecord() {
    FILE *file, *tempFile;
    Student s;
    int rollNumber;
    int found = 0;

    printf("Enter roll number of the student to modify: ");
    scanf("%d", &rollNumber);

    file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        perror("Error opening temporary file for writing");
        fclose(file);
        return;
    }

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNumber == rollNumber) {
            printf("Enter new name: ");
            getchar();  // Consume newline character left by scanf
            fgets(s.name, MAX_NAME_LENGTH, stdin);
            s.name[strcspn(s.name, "\n")] = '\0';  // Remove newline character

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            found = 1;
        }
        fwrite(&s, sizeof(Student), 1, tempFile);
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }

    fclose(file);
    fclose(tempFile);

    remove(DATABASE_FILE);
    rename("temp.dat", DATABASE_FILE);

    if (found) {
        printf("Student record modified.\n");
    }
}

// Function to remove a student's record
void removeStudentRecord() {
    FILE *file, *tempFile;
    Student s;
    int rollNumber;
    int found = 0;

    printf("Enter roll number of the student to remove: ");
    scanf("%d", &rollNumber);

    file = fopen(DATABASE_FILE, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }

    tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        perror("Error opening temporary file for writing");
        fclose(file);
        return;
    }

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.rollNumber != rollNumber) {
            fwrite(&s, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }

    fclose(file);
    fclose(tempFile);

    remove(DATABASE_FILE);
    rename("temp.dat", DATABASE_FILE);

    if (found) {
        printf("Student record removed.\n");
    }
}

// Function to display a student's record
void displayStudent(const Student *s) {
    printf("Roll Number: %d\n", s->rollNumber);
    printf("Name: %s\n", s->name);
    printf("Marks: %.2f\n", s->marks);
}

