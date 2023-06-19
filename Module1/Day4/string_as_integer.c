#include <stdio.h>
int stringToInt(const char *str) {
    int res = 0;
    int i = 0;
    while (str[i] != '\0') {
        int ival = str[i] - '0';
        res = res * 10 + ival;
        i++;
    }
    return res;
}
int main() {
    char str[100];
    printf("Enter a string of digits: ");
    scanf("%s", str);
    int num = stringToInt(str);
    printf("Converted integer: %d\n", num);
    return 0;
}