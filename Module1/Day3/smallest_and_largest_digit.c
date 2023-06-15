#include <stdio.h>
void findSmallestAndLargestDigits(int n, int numbers[]) {
    int i, j, smallestDigit, largestDigit;
    for (i = 0; i < n; i++) {
        int currentNumber = numbers[i];
        smallestDigit = 9;
        largestDigit = 0;
        if (currentNumber < 10) {
            printf("Not Valid\n");
            continue;
        }
        while (currentNumber > 0) {
            int digit = currentNumber % 10;
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }
            if (digit > largestDigit) {
                largestDigit = digit;
            }
            currentNumber /= 10;
        }
        printf("%d and %d\n", smallestDigit, largestDigit);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    findSmallestAndLargestDigits(n, numbers);
    return 0;
}