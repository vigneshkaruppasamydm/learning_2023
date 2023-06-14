#include <stdio.h>
void printExponent(double num) {
    unsigned long long *ptr = (unsigned long long *)&num;
    unsigned long long mask = 0x7FF0000000000000ULL;
    unsigned long long exponent = (*ptr & mask) >> 52;
    printf("Exponent in hexadecimal: 0x%llX\n", exponent);
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}
int main() {
    double x;
    printf("Enter a double number: ");
    scanf("%lf", &x);
    printExponent(x);
    return 0;
}