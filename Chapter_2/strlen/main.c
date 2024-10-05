#include <stdio.h>

int strlen(const char str[]){
    int i = 0;
    while(str[i] != '\0') ++i;
    return i;
}

int main(){
    char* str = "skibidi toilet";
    printf("len of %s is %d", str, strlen(str));
    return 0;
}