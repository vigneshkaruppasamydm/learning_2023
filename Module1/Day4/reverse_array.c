#include <stdio.h>
void reverseArray(int arr[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int arr[10];
    int length;
    printf("Enter the number of elements (up to 10): ");
    scanf("%d", &length);
    printf("Enter the elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    reverseArray(arr, length);
    printf("\nReversed Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}