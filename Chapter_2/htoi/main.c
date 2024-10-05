#include <stdio.h>

int lower(char c) {
    if (c >= 'A' && c <= 'Z') 
        return c + 'a' - 'A';
    else 
        return c;
}

int htoi(const char* hex) {
    int i = 0, n = 0, value;

    // Skip optional "0x" or "0X" prefix
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        i = 2;
    }

    for (; hex[i] != '\0'; ++i) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0'; 
        } else if (lower(hex[i]) >= 'a' && lower(hex[i]) <= 'f') {
            value = lower(hex[i]) - 'a' + 10; 
        } else {
            break;
        }

        n = 16 * n + value; 
    }

    return n;
}

int main(void) {
    int n = 0x12af;
    printf("%d, %d\n", n, htoi("12af"));  
}
