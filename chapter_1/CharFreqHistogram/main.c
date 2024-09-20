#include <stdio.h>

int main(){
    int i;
    char c;
    char freq[26] = {0};

    while ((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            ++freq[c - 'a'];
        } else if ( c >= 'A' && c <= 'Z') {
            ++freq[c - 'A'];
        }
    }

    for (i = 0; i < 26; ++i){
        printf("%c: ", 'a' + i);
        for (int j = 1; j <= freq[i]; ++j){
            if (freq[i]) printf("*");
        }
        printf("\n");
    }

    return 0;
}