#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void initializeStructArray(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}
void parseAndInitializeStructArray(char* input, struct Student* students, int size) {
    char* token = strtok(input, " ");
    for (int i = 0; i < size; i++) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
    }
}
void displayStructArray(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n",
               i + 1, students[i].rollno, students[i].name, students[i].marks);
    }
}
void sortStructArrayDescending(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    struct Student* students = malloc(size * sizeof(struct Student));
    initializeStructArray(students, size);
    char input[100];
    printf("Enter student details in the format 'rollno name marks':\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        parseAndInitializeStructArray(input, &students[i], 1);
    }
    printf("\nInitialized Array of Structures:\n");
    displayStructArray(students, size);
    sortStructArrayDescending(students, size);
    printf("\nSorted Array of Structures (Descending Order):\n");
    displayStructArray(students, size);
    free(students);
    return 0;
}