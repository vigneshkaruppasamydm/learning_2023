#include <stdio.h>
int main() {
    int arr[10];
    int len, min, max;
    printf("Enter the number of elements (up to 10): ");
    scanf("%d", &len);
    printf("Enter the elements:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}