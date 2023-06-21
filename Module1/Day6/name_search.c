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
void searchStructArrayByName(const struct Student* students, int size, const char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d, Name: %s, Marks: %.2f\n",
                   students[i].rollno, students[i].name, students[i].marks);
            found = 1;
        }
    }
    if (!found) {
        printf("Student with name '%s' not found.\n", name);
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
    char searchName[20];
    printf("\nEnter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    printf("\nSearch Result:\n");
    searchStructArrayByName(students, size, searchName);
    free(students);
    return 0;
}