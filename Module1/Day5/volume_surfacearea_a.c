#include <stdio.h>
struct Box {
    double length;
    double width;
    double height;
};
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}
double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}
int main() {
    struct Box myBox;
    printf("Enter the length: ");
    scanf("%lf", &myBox.length);
    printf("Enter the width: ");
    scanf("%lf", &myBox.width);
    printf("Enter the height: ");
    scanf("%lf", &myBox.height);
    struct Box* boxPtr = &myBox;
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
    return 0;
}