#include <stdio.h>

#define LONGLINE 10



int main(void){
    int c, linelen;
    linelen = 0;
    while ((c = getchar()) != EOF){
        if((c == ' ' || c == '\t') && linelen >= LONGLINE) {
            putchar('\n');
            linelen = 0;
        }
        else {
            putchar(c);
            ++linelen;
        }
    }

    return 0;
}