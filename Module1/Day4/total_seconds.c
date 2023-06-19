#include <stdio.h>
int getTotalSeconds(const char *timeStr) {
    int hours, minutes, seconds;
    sscanf(timeStr, "%d:%d:%d", &hours, &minutes, &seconds);
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    return totalSeconds;
}
int main() {
    char timeStr[100];
    printf("Enter the time in hh:mm:ss format: ");
    scanf("%s", timeStr);
    int totalSeconds = getTotalSeconds(timeStr);
    printf("Total seconds: %d\n", totalSeconds);
    return 0;
}