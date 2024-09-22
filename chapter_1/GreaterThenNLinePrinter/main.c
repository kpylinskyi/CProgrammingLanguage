#include <stdio.h>

#define MAXLINE 1000
#define LONG 8

int getlinelen(char line[], int maxlen);

int main(){
    int len;
    char line[MAXLINE];    

    while ((len = getlinelen(line, MAXLINE)) > 0)
    {
        if (len >= LONG){
            printf("%s", line);
        }
    }
    
    return 0;
}

int getlinelen(char line[], int maxlen){
    int i;
    char c;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}