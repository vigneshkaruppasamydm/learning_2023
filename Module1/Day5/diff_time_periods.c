#include <stdio.h>
struct Time {
    int hours;
    int minutes;
    int seconds;
};
struct Time calculateTimeDifference(struct Time start, struct Time end) {
    struct Time diff;
    int startTimeSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endTimeSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;
    int diffSeconds = endTimeSeconds - startTimeSeconds;
    diff.hours = diffSeconds / 3600;
    diff.minutes = (diffSeconds % 3600) / 60;
    diff.seconds = (diffSeconds % 3600) % 60;
    return diff;
}
int main() {
    struct Time startTime, endTime, diff;
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &(startTime.hours), &(startTime.minutes), &(startTime.seconds));
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &(endTime.hours), &(endTime.minutes), &(endTime.seconds));
    diff = calculateTimeDifference(startTime, endTime);
    printf("\nTime difference: %d hours %d minutes %d seconds\n", diff.hours, diff.minutes, diff.seconds);
    return 0;
}