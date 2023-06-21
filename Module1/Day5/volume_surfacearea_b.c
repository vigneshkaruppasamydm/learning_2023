#include <stdio.h>
struct Box {
    double length;
    double width;
    double height;
};
double calculateVolumeArrow(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}
double calculateSurfaceAreaArrow(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}
double calculateVolumeDot(struct Box* boxPtr) {
    return (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
}
double calculateSurfaceAreaDot(struct Box* boxPtr) {
    return 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);
}

int main() {
    struct Box myBox;
    printf("Enter the length: ");
    scanf("%lf", &(myBox.length));
    printf("Enter the width: ");
    scanf("%lf", &(myBox.width));
    printf("Enter the height: ");
    scanf("%lf", &(myBox.height));
    struct Box* boxPtr = &myBox;
    double volumeArrow = calculateVolumeArrow(boxPtr);
    double surfaceAreaArrow = calculateSurfaceAreaArrow(boxPtr);
    double volumeDot = calculateVolumeDot(boxPtr);
    double surfaceAreaDot = calculateSurfaceAreaDot(boxPtr);
    printf("Volume (Arrow Operator): %.2f\n", volumeArrow);
    printf("Total Surface Area (Arrow Operator): %.2f\n", surfaceAreaArrow);
    printf("Volume (Dot Representation): %.2f\n", volumeDot);
    printf("Total Surface Area (Dot Representation): %.2f\n", surfaceAreaDot);
    return 0;
}