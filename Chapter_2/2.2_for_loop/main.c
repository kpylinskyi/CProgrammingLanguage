#include <stdio.h>
#define LIM 10000

int main(void){
    const char* str = "skibidistring";
    int c, i;
    i = 0;
    while(i < LIM){
        c = str[i];
        if (c == EOF) break;
        if (c == '\n') break;
        if (c == '\0') break;

        ++i;
    }
    
    printf("%d", i);
}