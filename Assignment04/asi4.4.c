#include <stdio.h>

double calculate(double a, double b, char op);
int error_flag = 0;

int main() {
    double operand1, operand2;
    char operator;

    printf("Enter first operand: ");
    scanf("%lf", &operand1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second operand: ");
    scanf("%lf", &operand2);

    double result = calculate(operand1, operand2, operator);

    if (error_flag) {
        printf("An error occurred.\n");
    } else if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        printf("Result: %.2lf\n", result);
    } else {
        printf("Invalid operator.\n");
    }

    return 0;
}

double calculate(double a, double b, char op) {
    error_flag = 0; // Reset error flag

    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                error_flag = 1;
                printf("Error: Division by zero.\n");
                return 0;
            }
        default:
            error_flag = 1;
            printf("Error: Invalid operator.\n");
            return 0;
    }
}

