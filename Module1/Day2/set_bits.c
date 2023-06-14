#include <stdio.h>
int countSetBits(int *arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int num = *(arr + i);
        while (num > 0) {
            count += num & 1;
            num >>= 1;
        }
    }
    return count;
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%x", &arr[i]);
    }
    int result = countSetBits(arr, size);
    printf("Total number of set bits: %d\n", result);
   
    return 0;
}