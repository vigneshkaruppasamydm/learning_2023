#include <stdio.h>
struct Complex {
    double real;
    double imaginary;
};
void readComplex(struct Complex* complex) {
    printf("Enter the real part: ");
    scanf("%lf", &(complex->real));
    printf("Enter the imaginary part: ");
    scanf("%lf", &(complex->imaginary));
}
void writeComplex(struct Complex complex, const char* label) {
    printf("%s: %.2f + %.2fi\n", label, complex.real, complex.imaginary);
}
struct Complex addComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}
struct Complex multiplyComplex(struct Complex complex1, struct Complex complex2) {
    struct Complex result;
    result.real = complex1.real * complex2.real - complex1.imaginary * complex2.imaginary;
    result.imaginary = complex1.real * complex2.imaginary + complex1.imaginary * complex2.real;
    return result;
}
int main() {
    struct Complex complex1, complex2, sum, product;
    printf("Reading the first complex number:\n");
    readComplex(&complex1);
    printf("Reading the second complex number:\n");
    readComplex(&complex2);
    sum = addComplex(complex1, complex2);
    product = multiplyComplex(complex1, complex2);
    printf("\n");
    writeComplex(complex1, "Complex number 1");
    writeComplex(complex2, "Complex number 2");
    writeComplex(sum, "Sum");
    writeComplex(product, "Product");
    return 0;
}