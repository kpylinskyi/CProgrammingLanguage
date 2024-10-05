#include <stdio.h>

void squeeze(char * s, char c){
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void squeeze_str(char * s1, char * s2){
    int i, j, k;

    for (i = 0; s2[i] != '\0'; ++i){
        for (j = k = 0; s1[j] != '\0'; ++j){
            if (s1[j] != s2[i]){
                s1[k++] = s1[j];
            }
        }
        s1[k] = '\0';
    }
}

int main(void){
    char s[] = "squeeze";
    squeeze_str(s, "eze");
    printf("%s", s);

    return 0;
}