#include <stdio.h>
void swap(void *a, void *b, size_t size) {
    char *temp = (char *)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    char ch1, ch2;
    printf("Enter two characters: ");
    scanf(" %c %c", &ch1, &ch2);
    printf("Before swapping: ch1 = %c, ch2 = %c\n", ch1, ch2);
    swap(&ch1, &ch2, sizeof(char));
    printf("After swapping: ch1 = %c, ch2 = %c\n", ch1, ch2);
    float float1, float2;
    printf("Enter two floating-point numbers: ");
    scanf("%f %f", &float1, &float2);
    printf("Before swapping: float1 = %f, float2 = %f\n", float1, float2);
    swap(&float1, &float2, sizeof(float));
    printf("After swapping: float1 = %f, float2 = %f\n", float1, float2);
    return 0;
}