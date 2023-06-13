#include <stdio.h>
int main() {
    float num1, num2;
    char operator;
    float result;
    printf("Enter Operand 1: ");
    scanf("%f", &num1);
    printf("Enter Operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter Operand 2: ");
    scanf("%f", &num2);
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }
    return 0;
}