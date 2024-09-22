#include <stdio.h>

#define MAXLINE 1000

int maxlen;
char line[MAXLINE];
char longest[MAXLINE];

int getlinelen(void);
void copy(void);

int main(){
    int len; 
    extern int maxlen;
    extern char longest[];
    
    maxlen = 0;
    while((len = getlinelen()) > 0)
    if (len > maxlen){
        maxlen = len;
        copy();
    }
    if (maxlen > 0) printf("%slen: %d", longest, maxlen);
    return 0;
}

int getlinelen(){
    char c;
    int i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(){
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0'){
        ++i;
    }
}