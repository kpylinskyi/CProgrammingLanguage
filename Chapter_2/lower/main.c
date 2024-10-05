#include <stdio.h>

signed char lower(int c){
    return (c >= 'A' && c <= 'Z') ? (signed char) c + 'a' - 'A' : c;
}

signed char upper(int c){
    return (c >= 'a' && c <= 'z') ? (signed char) c - 'a' + 'A' : c;
}

int main(void){
    int c;
    while((c=getchar()) != EOF){
        putchar(upper(c));
    }

    return 0;
}