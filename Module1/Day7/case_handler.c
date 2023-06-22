#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void copyFile(FILE *sourceFile, FILE *destinationFile, int caseOption) {
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (caseOption == 'u') {
            ch = toupper(ch);
        } else if (caseOption == 'l') {
            ch = tolower(ch);
        } else if (caseOption == 's') {
            static int isFirstCharacter = 1;
            if (isFirstCharacter) {
                ch = toupper(ch);
                isFirstCharacter = 0;
            } else {
                ch = tolower(ch);
            }
        }
        fputc(ch, destinationFile);
    }
}
int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    int caseOption = 0;
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <sourcefile> <destinationfile>\n");
        printf("Options: -u (uppercase), -l (lowercase), -s (sentence case)\n");
        return 0;
    }
    caseOption = argv[1][1];  
    strcpy(sourceFileName, argv[2]);
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 0;
    }
    strcpy(destinationFileName, argv[3]);
    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 0;
    }
    copyFile(sourceFile, destinationFile, caseOption);
    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}