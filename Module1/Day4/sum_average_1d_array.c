#include <stdio.h>
int main() {
    int arr[10];
    int len, sum = 0;
    float avg;
    printf("Enter the number of elements (up to 10): ");
    scanf("%d", &len);
    printf("Enter the elements:\n");
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    avg = (float)sum / len;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    return 0;
}