#include <stdio.h>
int main() {
    int arr[10];
    int length;
    int sumEven = 0;
    int sumOdd = 0;
    printf("Enter the number of elements (up to 10): ");
    scanf("%d", &length);
    printf("Enter the elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        } else {
            sumOdd += arr[i];
        }
    }
    int difference = sumEven - sumOdd;
    printf("Sum of even elements: %d\n", sumEven);
    printf("Sum of odd elements: %d\n", sumOdd);
    printf("Difference: %d\n", difference);
    return 0;
}