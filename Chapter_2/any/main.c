#include <stdio.h>

int any(const char* s1, const char* s2) {
    int i, j;

    // Iterate over each character in s1
    for (i = 0; s1[i] != '\0'; ++i) {
        // Check if s1[i] matches any character in s2
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;  // Return the index of the first match
            }
        }
    }
    
    // Return -1 if no match is found
    return -1;
}

int main(void) {
    printf("%d\n", any("any", "y"));  // Should print 2, as 'y' is at index 2 in "any"
    printf("%d\n", any("hello", "lo"));  // Should print 2, as 'l' is at index 2 in "hello"
    printf("%d\n", any("hello", "x"));  // Should print -1, as 'x' is not found in "hello"

    return 0;
}
