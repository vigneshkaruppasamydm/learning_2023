#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;
void readDataFromFile(LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    char line[100];
    char *token;
    int count = 0;
    fgets(line, sizeof(line), file); 
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        logEntries[count].entryNo = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[count].sensorNo, token);
        token = strtok(NULL, ",");
        logEntries[count].temperature = atof(token);
        token = strtok(NULL, ",");
        logEntries[count].humidity = atoi(token);
        token = strtok(NULL, ",");
        logEntries[count].light = atoi(token);
        token = strtok(NULL, ",");
        strcpy(logEntries[count].timestamp, token);
        count++;
    }
    *numEntries = count;
    fclose(file);
}
void displayLogEntries(LogEntry logEntries[], int numEntries) {
    printf("%-8s %-10s %-12s %-8s %-6s\n", "EntryNo", "SensorNo", "Temperature", "Humidity", "Light");
    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-10s %-12.2f %-8d %-6d\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light);
    }
}
int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    readDataFromFile(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);
    return 0;
}