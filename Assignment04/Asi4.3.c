#include <stdio.h>

double calculate(double a, double b, char op);

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

    if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        printf("Result: %.2lf\n", result);
    } else {
        printf("Invalid operator.\n");
    }

    return 0;
}

double calculate(double a, double b, char op) {
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
                printf("Error: Division by zero.\n");
                return 0;
            }
        default:
            printf("Error: Invalid operator.\n");
            return 0;
    }
}

