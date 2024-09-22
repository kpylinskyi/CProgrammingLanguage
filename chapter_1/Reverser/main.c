#include <stdio.h>

#define MAXLEN 1000

int getlinelen(char line[], int maxlen);
void reverse(char s[]);

int main() {
    char line[MAXLEN];
    int len;

    while ((len = getlinelen(line, MAXLEN)) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int getlinelen(char line[], int maxlen) {
    int i;
    char c;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;  // Include newline in the array
        ++i;
    }

    line[i] = '\0';  // Null-terminate the string
    return i;  // Return the length of the line
}

void reverse(char s[]) {
    int i = 0;
    int j = 0;

    // Find the end of the string (ignoring newline)
    while (s[j] != '\0') {
        ++j;
    }
    --j;  // Move j back to the last character before null terminator

    // If the last character is a newline, adjust j
    if (s[j] == '\n') {
        --j;  // Ignore the newline for reversal
    }

    // Reverse the string
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
}
