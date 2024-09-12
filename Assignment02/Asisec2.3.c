#include <stdio.h>

int main() {
    int deptNo;
    char dsgnCode;
    int empId;

    printf("Enter Employee Id: ");
    scanf("%d", &empId);
    printf("Enter Dept No: ");
    scanf("%d", &deptNo);
    printf("Enter Designation Code: ");
    scanf(" %c", &dsgnCode);

    char *deptName;
    char *designation;

    switch (deptNo) {
        case 10:
            deptName = "Marketing";
            break;
        case 20:
            deptName = "Management";
            break;
        case 30:
            deptName = "Sales";
            break;
        case 40:
            deptName = "Designing";
            break;
        default:
            printf("Invalid Dept No.\n");
            return 1;
    }

    switch (dsgnCode) {
        case 'M':
            designation = "Manager";
            break;
        case 'S':
            designation = "Supervisor";
            break;
        case 'O':
            designation = "Security Officer";
            break;
        case 'C':
            designation = "Clerk";
            break;
        default:
            printf("Invalid Designation Code.\n");
            return 1;
    }

    printf("Employee with employee id %d is working in \"%s\" department as \"%s\".\n", empId, deptName, designation);

    return 0;
}

